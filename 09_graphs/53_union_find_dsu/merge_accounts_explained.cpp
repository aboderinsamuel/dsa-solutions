// ============================================================================
// LeetCode 721 - Accounts Merge
//
// PROBLEM: accounts[i] = [name, email1, email2, ...]
//          Two accounts are the same person if they share AT LEAST ONE email.
//          Merging is TRANSITIVE: A~B and B~C  =>  A~B~C.
//          Output: [name, ...emails sorted alphabetically] per person.
//
// WHY DSU: transitive grouping IS the disjoint-set-union job description.
// ============================================================================

struct DSU {
    // parent[x] = the node x points to. If parent[x] == x, then x is a ROOT.
    // The root is the identity of the whole set: two nodes are in the same
    // group if and only if they climb to the same root.
    //
    //   parent = [0, 0, 2, 3]  means:  1 -> 0 (root),  2 is its own root,
    //                                  3 is its own root.
    vector<int> parent;

    // rank_[r] = an UPPER BOUND on the height of the tree rooted at r.
    // Not the true height - path halving flattens trees without updating rank.
    // Trailing underscore avoids colliding with std::rank from <type_traits>,
    // which gets pulled in transitively under `using namespace std`.
    vector<int> rank_;

    // `explicit` blocks implicit conversion. Without it, `DSU d = 5;` compiles
    // and silently turns an int into a DSU. Nonsense, so forbid it.
    // `DSU d(5)` still works exactly as before.
    explicit DSU(int n) : parent(n), rank_(n, 0) {
        // Every node starts alone, as its own root, in a set of size 1.
        //   n = 4  ->  parent = [0, 1, 2, 3],  rank_ = [0, 0, 0, 0]
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    // find(x): climb to the root of x's set, flattening the path on the way.
    int find(int x) {
        // Keep climbing while x is not its own parent (i.e. not the root).
        while (parent[x] != x) {
            // PATH HALVING: point x at its GRANDparent before moving up.
            // This is what keeps future find() calls cheap.
            //
            //   Before:  3 -> 2 -> 1 -> 0        (chain, find(3) = 3 hops)
            //   Step 1:  parent[3] = parent[parent[3]] = parent[2] = 1
            //            3 -> 1 -> 0,  then x becomes 1
            //   Step 2:  parent[1] = parent[parent[1]] = parent[0] = 0
            //            1 -> 0,       then x becomes 0 -> loop ends
            //   After:   3 -> 1 -> 0             (chain halved, permanently)
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;   // x is now the root
    }

    // unite(a, b): merge a's set with b's set.
    // Returns true if a merge actually happened, false if they were already
    // together. That bool is the entire answer to LC 684 (Redundant Connection).
    bool unite(int a, int b) {
        int rootA = find(a), rootB = find(b);

        // Same root => already in the same group. Nothing to do.
        // In 684 this is the cycle-detection signal. Here we just skip.
        if (rootA == rootB) return false;

        // UNION BY RANK: hang the SHALLOWER tree under the DEEPER one.
        // Doing it the other way round would make the result taller and
        // eventually degrade find() into a linear walk.
        // The swap just guarantees rootA is the deeper of the two.
        if (rank_[rootA] < rank_[rootB]) swap(rootA, rootB);

        // rootB (shallower) now points at rootA (deeper).
        // Its entire subtree comes along for free - no other pointers move.
        parent[rootB] = rootA;

        // Rank only grows on a TIE. If rootA was already deeper, rootB's
        // tree fits inside rootA's existing depth and nothing got taller.
        //
        //   rank 2 under rank 3  ->  still rank 3   (no change)
        //   rank 2 under rank 2  ->  now  rank 3    (one level added)
        if (rank_[rootA] == rank_[rootB]) ++rank_[rootA];

        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // MODELING DECISION - the crux of this problem.
        // DSU nodes are ACCOUNT INDICES (0..n-1), not emails.
        // Why: at output time we need the person's NAME, which lives at
        // accounts[i][0]. With index nodes, accounts[root][0] gives it for
        // free. With email nodes we'd need a separate email->name map.
        DSU dsu(n);

        // The bridge between "emails" and "account indices":
        //   email -> the FIRST account index that claimed this email.
        // Deliberately stores the first owner, NOT the current root - roots
        // change as merges happen, so we resolve lazily in pass 2 instead.
        unordered_map<string, int> emailOwner;

        // ---------------------------------------------------------------
        // PASS 1: scan every email, union accounts that share one.
        // ---------------------------------------------------------------
        for (int i = 0; i < n; ++i) {
            // j starts at 1, NOT 0. Index 0 is the NAME, not an email.
            // Forgetting this puts "John" in the email map and it shows up
            // in the output as if it were an address.
            for (int j = 1; j < (int) accounts[i].size(); ++j) {
                const string& email = accounts[i][j];   // const& = no copy

                auto it = emailOwner.find(email);
                if (it == emailOwner.end()) {
                    // First time seeing this email: account i claims it.
                    emailOwner[email] = i;
                } else {
                    // Already claimed by account it->second. Shared email
                    // means same person, so merge the two accounts.
                    dsu.unite(i, it->second);
                }
            }
        }
        //
        //  WORKED EXAMPLE - pass 1 on:
        //    0: ["John", "johnsmith", "john_newyork"]
        //    1: ["John", "johnsmith", "john00"]
        //    2: ["Mary", "mary"]
        //    3: ["John", "johnnybravo"]
        //
        //    (0,"johnsmith")    new    -> emailOwner["johnsmith"] = 0
        //    (0,"john_newyork") new    -> emailOwner["john_newyork"] = 0
        //    (1,"johnsmith")    SEEN@0 -> unite(1, 0)   accounts 0,1 merge
        //    (1,"john00")       new    -> emailOwner["john00"] = 1
        //    (2,"mary")         new    -> emailOwner["mary"] = 2
        //    (3,"johnnybravo")  new    -> emailOwner["johnnybravo"] = 3
        //
        //  Accounts 0 and 3 are BOTH "John" but never merge - no shared
        //  email. Same name does NOT mean same person. That is the trap
        //  the test cases are built around.

        // ---------------------------------------------------------------
        // PASS 2: bucket every email under its group's ROOT.
        // ---------------------------------------------------------------
        // map (ordered) keyed by root; set<string> keeps emails sorted on
        // insertion, which satisfies the "sorted emails" requirement with
        // no separate sort pass.
        map<int, set<string>> groups;

        for (auto& [email, owner] : emailOwner) {
            // dsu.find(owner) - NOT just `owner`. This is the line that
            // makes the merge actually take effect.
            //
            //   "john00" was registered under account 1.
            //   But account 1 merged into 0 during pass 1.
            //   find(1) returns 0, so "john00" lands in group 0. Correct.
            groups[dsu.find(owner)].insert(email);
        }
        //
        //  WORKED EXAMPLE - pass 2:
        //    "johnsmith"    owner 0 -> find(0)=0 -> group 0
        //    "john_newyork" owner 0 -> find(0)=0 -> group 0
        //    "john00"       owner 1 -> find(1)=0 -> group 0   <-- redirected
        //    "mary"         owner 2 -> find(2)=2 -> group 2
        //    "johnnybravo"  owner 3 -> find(3)=3 -> group 3

        // ---------------------------------------------------------------
        // PASS 3: build the output rows.
        // ---------------------------------------------------------------
        vector<vector<string>> result;
        result.reserve(groups.size());   // one allocation instead of regrowth

        for (auto& [root, emails] : groups) {
            // accounts[root][0] is the name. Every account merged into this
            // group belongs to the same person, so ANY member's name works -
            // and root is guaranteed to be a valid account index.
            vector<string> account{accounts[root][0]};

            // Append the already-sorted emails after the name.
            account.insert(account.end(), emails.begin(), emails.end());

            // move() transfers ownership instead of deep-copying every
            // string in the row. Free, and a C++ interviewer notices.
            result.push_back(move(account));
        }

        return result;
        //
        //  FINAL OUTPUT:
        //    ["John", "john00", "john_newyork", "johnsmith"]   (sorted)
        //    ["Mary", "mary"]
        //    ["John", "johnnybravo"]
    }
};

// ============================================================================
// COMPLEXITY
//   N = accounts (<=1000), K = emails per account (<=10),
//   E = N*K = total emails (<=10,000), L = email length (<=30)
//
// TIME: O(E * L * log E)
//   Pass 1 touches each email once. Each hash lookup costs O(L) because
//   hashing a string must read all its characters; each union is effectively
//   constant. So pass 1 is O(E*L).
//   Pass 2 DOMINATES: inserting into a set does log E comparisons, and each
//   string comparison costs O(L). Hence E * L * log E.
//   Counterintuitive but true: the cost here is STRING HANDLING, not the
//   disjoint-set operations, even though the problem is tagged union-find.
//   Concretely: 10,000 * 30 * 14 ~ 4 million character ops.
//
// SPACE: O(E * L)
//   emailOwner holds every email once; groups holds every email again; each
//   string is L characters. The DSU arrays are only O(N) - the small part.
// ============================================================================
