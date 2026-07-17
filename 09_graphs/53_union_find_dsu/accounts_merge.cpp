#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) return;
        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        }else if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);

        //map email -> account index
        unordered_map<string, int> emailToId;

        //step 1: Union accounts that share emails
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];

                if(emailToId.find(email) == emailToId.end()){
                    //First time seeing this email
                    emailToId[email] = i;
                }else{
                    //Email already exists, union current account with existing one
                    uf.unite(i, emailToId[email]);
                }
            }
        }
        //step 2 : Group emails by their root account
        unordered_map<int, set<string>> rootToEmails;

        for(auto& [email, id] : emailToId){
            int root = uf.find(id);
            rootToEmails[root].insert(email);
        }
        //step 3 : Build the result
        vector<vector<string>> result;
        for(auto& [root, emails] : rootToEmails){
            vector<string> account;
            account.push_back(accounts[root][0]); //Name

            //Emails are already sorted because we used set
            for(const string& email : emails){
                account.push_back(email);
            }
            result.push_back(account);
        }
        return result;
    }
};