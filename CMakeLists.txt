cmake_minimum_required(VERSION 3.25)
project(cpp_dsa_thita)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(add_all_cpp_in_dir DIR_PATH)
file(GLOB CPP_FILES CONFIGURE_DEPENDS "${DIR_PATH}/*.cpp")
foreach(file ${CPP_FILES})
get_filename_component(EXE_NAME ${file} NAME_WE)
add_executable(${EXE_NAME} ${file})
endforeach()
endfunction()

# ======== 0. FOUNDATIONS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/00_foundations/00a_sorting_algorithms)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/00_foundations/00b_recursion_fundamentals)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/00_foundations/00c_math_number_theory)

# ======== I. TWO POINTER PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/01_converging)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/02_string_reversal)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/03_inplace_array_modification)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/04_fast_and_slow)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/05_fixed_separation)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/06_string_comparison_special_chars)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/01_two_pointers/07_expanding_from_center)

# ======== II. ARRAY/MATRIX MANIPULATION PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/08_plus_one)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/09_merge_sorted_array)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/10_inplace_rotation)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/11_spiral_traversal)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/12_set_matrix_zeroes)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/13_product_except_self)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/14_hashing_frequency_map)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/15_hashing_seen_check)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/16_prefix_sum)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/02_array_matrix/17_cyclic_sort)

# ======== III. LINKED LIST MANIPULATION PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/03_linked_list/18_merge_two_sorted_lists)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/03_linked_list/19_inplace_reversal)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/03_linked_list/20_intersection_detection)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/03_linked_list/21_addition_of_numbers)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/03_linked_list/22_reordering_and_partitioning)

# ======== IV. TREE TRAVERSAL PATTERNS (DFS & BFS) ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/23_recursive_preorder)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/24_recursive_inorder)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/25_recursive_postorder)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/26_level_order_traversal)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/27_lowest_common_ancestor)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/04_trees/28_serialization_deserialization)

# ======== V. SLIDING WINDOW PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/05_sliding_window/29_fixed_size_window)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/05_sliding_window/30_variable_size_window)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/05_sliding_window/31_character_frequency_matching)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/05_sliding_window/32_monotonic_queue)

# ======== VI. STACK PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/33_valid_parentheses)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/34_min_stack_design)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/35_simulation_and_backtracking)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/36_expression_evaluation)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/37_monotonic_stack)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/06_stack/38_largest_rectangle_histogram)

# ======== VII. HEAP (PRIORITY QUEUE) PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/07_heap_priority_queue/39_top_k_elements)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/07_heap_priority_queue/40_k_way_merge)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/07_heap_priority_queue/41_two_heaps_for_median)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/07_heap_priority_queue/42_scheduling_minimum_cost)

# ======== VIII. BINARY SEARCH PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/08_binary_search/43_sorted_array_search)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/08_binary_search/44_first_last_occurrence)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/08_binary_search/45_rotated_array_min_max)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/08_binary_search/46_binary_search_on_answer)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/08_binary_search/47_median_kth_two_arrays)

# ======== IX. GRAPH TRAVERSAL PATTERNS (DFS & BFS) ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/48_dfs_connected_components)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/49_bfs_connected_components)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/50_deep_copy_and_cloning)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/51_dfs_cycle_detection_directed)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/52_bfs_topological_sort_kahn)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/53_union_find_dsu)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/54_shortest_path_bellman_ford)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/55_shortest_path_dijkstra)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/56_bidirectional_bfs)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/57_minimum_spanning_tree)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/09_graphs/58_bridges_and_articulation_points)

# ======== X. GREEDY PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/60_sorting_based_greedy)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/61_interval_merging_scheduling)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/62_jump_game)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/63_buy_sell_stock)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/64_task_scheduling)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/65_gas_station_circuit)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/10_greedy/66_line_sweep)

# ======== XI. BACKTRACKING PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/67_subsets)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/68_permutations)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/69_combination_sum)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/70_parentheses_generation)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/71_word_search_grid_path)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/72_palindrome_partitioning)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/11_backtracking/73_n_queens_constraint_satisfaction)

# ======== XII. DYNAMIC PROGRAMMING PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/74_fibonacci_style)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/75_kadane_max_min_subarray)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/76_unique_paths)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/77_01_knapsack)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/78_coin_change)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/79_longest_common_subsequence)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/80_word_break)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/81_longest_increasing_subsequence)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/82_stock_problems)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/83_edit_distance)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/84_interval_dp)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/12_dynamic_programming/85_catalan_numbers)

# ======== XIII. STRING MANIPULATION PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/86_anagram_check)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/87_palindrome_check)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/88_repeated_substring_detection)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/89_naive_kmp_rabin_karp_search)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/90_integer_roman_conversion)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/13_strings/91_multiply_strings)

# ======== XIV. BIT MANIPULATION PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/14_bit_manipulation/92_power_of_two_four)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/14_bit_manipulation/93_bitwise_and_set_bit_count)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/14_bit_manipulation/94_bitwise_xor_single_missing)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/14_bit_manipulation/95_bitwise_dp_counting_bits)

# ======== XV. DESIGN PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/15_design/96_general_design)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/15_design/97_tries)

# ======== XVI. SEGMENT TREE & FENWICK TREE PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/16_segment_fenwick_tree/98_fenwick_tree_prefix_queries)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/16_segment_fenwick_tree/99_segment_tree_range_sum)

# ======== XVII. INTERVAL PATTERNS ========
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/17_intervals/100_insert_and_merge)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/17_intervals/101_non_overlapping_intervals)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/17_intervals/102_meeting_rooms)
add_all_cpp_in_dir(${CMAKE_SOURCE_DIR}/17_intervals/103_min_interval_query)


add_executable(twosum.cpp 01_two_pointers/01_converging/twosum.cpp
        01_two_pointers/01_converging/3sum.cpp
        01_two_pointers/01_converging/4sum.cpp
        01_two_pointers/02_string_reversal/reverse_string.cpp
        01_two_pointers/02_string_reversal/reverseVowels.cpp
        01_two_pointers/03_inplace_array_modification/move_zeros.cpp
        01_two_pointers/03_inplace_array_modification/separate-black-and-white-balls.cpp
        00_foundations/two-sum.cpp
        01_two_pointers/01_converging/boats-to-save-people.cpp
        01_two_pointers/01_converging/squares-of-sorted-array.cpp
        01_two_pointers/02_string_reversal/reverse-words-in-a-string.cpp
        01_two_pointers/03_inplace_array_modification/remove-duplicates-from-sorted-array.cpp
        01_two_pointers/03_inplace_array_modification/remove-duplicates-from-sorted-array-ii.cpp
        01_two_pointers/03_inplace_array_modification/sort-colors.cpp
        01_two_pointers/03_inplace_array_modification/string-compression.cpp
        01_two_pointers/04_fast_and_slow/Linked-List-Cycle.cpp
        01_two_pointers/04_fast_and_slow/Find-Duplicate-Number.cpp
        01_two_pointers/04_fast_and_slow/is-subsequence.cpp
        01_two_pointers/04_fast_and_slow/happy-number.cpp
        "01_two_pointers/05_fixed_separation/remove-nth-node-from-linkedlist.cpp"
        01_two_pointers/05_fixed_separation/remove-nth-node-from-linkedlist.cpp
        01_two_pointers/05_fixed_separation/middle-of-a-linked-list.cpp
        01_two_pointers/05_fixed_separation/delete-middle-node-of-a-linked-list.cpp
        01_two_pointers/06_string_comparison_special_chars/backspace-string-compare.cpp
        01_two_pointers/07_expanding_from_center/longest-palindromic-substring.cpp
        01_two_pointers/07_expanding_from_center/Palindromic-substrings.cpp
        02_array_matrix/08_plus_one/plus-one.cpp
        02_array_matrix/09_merge_sorted_array/merge-sorted-array.cpp
        02_array_matrix/10_inplace_rotation/rotate-array.cpp
        02_array_matrix/10_inplace_rotation/rotate-image.cpp
        02_array_matrix/11_spiral_traversal/spiral-matrix.cpp
        02_array_matrix/11_spiral_traversal/spiral-matrix-ii.cpp
        02_array_matrix/11_spiral_traversal/spiral-matrix-iii.cpp
        02_array_matrix/11_spiral_traversal/spiral-matrix-iv.cpp
        02_array_matrix/12_set_matrix_zeroes/set-matrix-zero.cpp
        01_two_pointers/06_string_comparison_special_chars/removing_stars_from_a_string.cpp
        02_array_matrix/08_plus_one/multiply_strings.cpp
        02_array_matrix/12_set_matrix_zeroes/game-of-life.cpp
        02_array_matrix/12_set_matrix_zeroes/diagonal-traverse.cpp
        02_array_matrix/13_product_except_self/product-of-array-except-self.cpp
        02_array_matrix/13_product_except_self/longest-mountain-in-array.cpp
        02_array_matrix/14_hashing_frequency_map/valid-anagram.cpp
        02_array_matrix/14_hashing_frequency_map/group-anagrams.cpp
        02_array_matrix/14_hashing_frequency_map/top-k-frequent-elements.cpp
        02_array_matrix/14_hashing_frequency_map/sort-characters-by-frequency.cpp
        02_array_matrix/14_hashing_frequency_map/task-Scheduler.cpp
        02_array_matrix/15_hashing_seen_check/Intersection_of_two_arrays.cpp
        02_array_matrix/15_hashing_seen_check/linkedlist-cycle.cpp
        02_array_matrix/15_hashing_seen_check/longestSubstring-without-repeating-characters.cpp
        "02_array_matrix/16_prefix_sum-Subarray and Range Query/minimumSize-subarray-sum.cpp"
        "02_array_matrix/16_prefix_sum-Subarray and Range Query/max-consecutive-ones-iii.cpp"
        "02_array_matrix/16_prefix_sum-Subarray and Range Query/product-of-the-last-k-numbers.cpp"
        "02_array_matrix/16_prefix_sum-Subarray and Range Query/frequency-of-the-most-frequent-element.cpp"
        "02_array_matrix/16_prefix_sum-Subarray and Range Query/split-array-largest-sum.cpp"
        02_array_matrix/17_Array-cyclic_sort/missing-number.cpp
        02_array_matrix/17_Array-cyclic_sort/find_all_numbers_disappeard_in_an_array.cpp
        02_array_matrix/17_Array-cyclic_sort/find-all-duplicates-in-an-array.cpp
        02_array_matrix/17_Array-cyclic_sort/first-missing-positive.cpp
        03_linked_list/18_merge_two_sorted_lists/approaches.cpp
        03_linked_list/18_merge_two_sorted_lists/merge-two-sorted-lists.cpp
        03_linked_list/18_merge_two_sorted_lists/extra.cpp
        03_linked_list/18_merge_two_sorted_lists/merge-k-sorted-lists.cpp
        03_linked_list/18_merge_two_sorted_lists/merge-k-full.cpp
        03_linked_list/19_inplace_reversal/Palindrome_linked_list.cpp
        03_linked_list/19_inplace_reversal/reverse-linked-list.cpp
        03_linked_list/21_addition_of_numbers/plus-one-linked-list.cpp
        04_trees/23_recursive_preorder/Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal.cpp
        04_trees/24_recursive_inorder/binary-tree-inorder-traversal.cpp
        04_trees/24_recursive_inorder/kth-smallest-element-in-a-bst.cpp
        04_trees/25_recursive_postorder/balanced-binary-tree.cpp
        04_trees/25_recursive_postorder/kth-largest-perfect-subtree-size-in-binary-tree.cpp
        04_trees/25_recursive_postorder/maximum-depth-of-binary-tree.cpp
        04_trees/25_recursive_postorder/house-robber-iii.cpp
        04_trees/25_recursive_postorder/binary-tree-maximum-path-sum.cpp
        04_trees/25_recursive_postorder/height-of-binary-tree-after-subtree-removal-queries.cpp
        04_trees/27_lowest_common_ancestor/lowest-common-ancestor-of-a-binary-tree.cpp
        04_trees/27_lowest_common_ancestor/lowest-common-ancestor-of-a-bst.cpp
        "04_trees/26_level_order_traversal-(Breadth-First-Search)/find-largest-value-in-each-tree-node.cpp"
        "04_trees/26_level_order_traversal-(Breadth-First-Search)/maximum-level-sum-of-a-binary-tree.cpp"
        04_trees/28_serialization_deserialization/subtree-of-another-tree.cpp
        04_trees/28_serialization_deserialization/serialize-and-deserialize-binary-tree.cpp
        04_trees/28_serialization_deserialization/serialize-and-deserialize-BST.cpp
        04_trees/28_serialization_deserialization/find-duplicate-subtrees.cpp
        05_sliding_window/29_fixed_size_window/maxSum-subarray-of-sizeK.cpp
        05_sliding_window/30_variable_size_window/min-subarray-len.cpp
        "05_sliding_window/29_fixed_size_window/3318-Find-X-Sum-of-All-K-Long-Subarrays-I.cpp"
        05_sliding_window/29_fixed_size_window/3254-find-the-power-of-K-size-Subarrays-i.cpp
        05_sliding_window/30_variable_size_window/contains-duplicate-ii.cpp
        05_sliding_window/30_variable_size_window/3347-maximum-frequency-of-an-element-after-performing-operations-ii.cpp
        06_stack/33_valid_parentheses/valid-parenthesis.cpp
        06_stack/34_min_stack_design/minStack.cpp
        06_stack/37_monotonic_stack/496-Next-Greater-Element-I.cpp
        06_stack/37_monotonic_stack/496-Next-Greater-Element-I-BRUTEFORCE.cpp
        06_stack/37_monotonic_stack/739-Daily-Temperatures.cpp
        07_heap_priority_queue/39_top_k_elements/take-gifts-from-the-richest-pile.cpp
        07_heap_priority_queue/39_top_k_elements/kth-largest-element-in-a-stream.cpp
        08_binary_search/43_sorted_array_search/binarySearch.cpp
        08_binary_search/43_sorted_array_search/search-a-2D-array.cpp
        08_binary_search/46_binary_search_on_answer/Koko-eating-bananas.cpp
        08_binary_search/47_median_kth_of_two_arrays/median_of_two_sorted_arrays.cpp
        09_graphs/48_dfs_connected_components/flood-fill.cpp
        09_graphs/48_dfs_connected_components/200-number-of-islands.cpp
        09_graphs/49_bfs_connected_components/rotting-oranges.cpp
        09_graphs/56_bidirectional_bfs/bus-routes.cpp
        13_strings/87_palindrome_check/valid_palindrome.cpp
        13_strings/87_palindrome_check/valid_palindrome_check.cpp
        15_design/96_general_design/insert_delete_getRandom.cpp
        15_design/96_general_design/LRU_Cache.cpp
        14_bit_manipulation/92_power_of_two_four/power_of_2.cpp
        14_bit_manipulation/92_power_of_two_four/power_of_four.cpp
        14_bit_manipulation/92_power_of_two_four/power_of_3.cpp
        12_dynamic_programming/74_fibonacci_style/climbing_stairs.cpp
        12_dynamic_programming/74_fibonacci_style/fibonacci_number.cpp
        12_dynamic_programming/74_fibonacci_style/minCost_climbing_stairs.cpp
        04_trees/24_recursive_inorder/same-tree.cpp
        04_trees/24_recursive_inorder/reverse_binary_trees.cpp
        12_dynamic_programming/74_fibonacci_style/house_robber.cpp
        12_dynamic_programming/74_fibonacci_style/house_robber_ii.cpp
        14_bit_manipulation/93_bitwise_and_set_bit_count/number_of_1_bits.cpp
        14_bit_manipulation/93_bitwise_and_set_bit_count/counting_bits.cpp
        14_bit_manipulation/93_bitwise_and_set_bit_count/add_binary.cpp
        14_bit_manipulation/93_bitwise_and_set_bit_count/reverse_bits.cpp
        10_greedy/lemonade_change.cpp
        10_greedy/maximum_subarray.cpp
        10_greedy/65_gas_station_circuit/Gas_Station.cpp
        10_greedy/62_jump_game/jump-game.cpp
        10_greedy/62_jump_game/jump_game_ii.cpp
        10_greedy/61_interval_merging_scheduling/partition_labels.cpp
        10_greedy/hand_of_straights.cpp
        10_greedy/Candy.cpp
        17_intervals/non_overlapping_intervals.cpp
        11_backtracking/sum-of-all-subset-xor-totals.cpp
        11_backtracking/67_subsets/subsets.cpp
        11_backtracking/67_subsets/subsets_ii.cpp
        11_backtracking/68_permutations/permutations.cpp
        11_backtracking/68_permutations/permutations_ii.cpp
        11_backtracking/69_combination_sum/combinations.cpp
        11_backtracking/69_combination_sum/letter_combinations_of_a_phone_number.cpp
        11_backtracking/69_combination_sum/combination_sum.cpp
        11_backtracking/69_combination_sum/combination_sum_ii.cpp
        11_backtracking/73_n_queens_constraint_satisfaction/N_Queens.cpp
        11_backtracking/73_n_queens_constraint_satisfaction/n_queens_.cpp
        11_backtracking/73_n_queens_constraint_satisfaction/n_queens_.cpp
        11_backtracking/73_n_queens_constraint_satisfaction/N_Queens_II.cpp
        11_backtracking/72_palindrome_partitioning/Palindrome_Partitioning.cpp
        11_backtracking/71_word_search_grid_path/word_search.cpp
        00_foundations/00b_recursion_fundamentals/nn.cpp
        12_dynamic_programming/N-th_tribonacci.cpp
        12_dynamic_programming/78_coin_change/coin_change.cpp
        12_dynamic_programming/81_longest_increasing_subsequence/longest_increasing_subsequence.cpp
        12_dynamic_programming/Decode_ways.cpp
        12_dynamic_programming/75_kadane_max_min_subarray/maximum_product_subarray.cpp
        12_dynamic_programming/80_word_break/word_break.cpp
        09_graphs/find_the_town_judge.cpp
        09_graphs/island_perimeter.cpp
        09_graphs/48_dfs_connected_components/clone_graph_unsafe.cpp
        09_graphs/49_bfs_connected_components/cloned_graph.cpp
        01_two_pointers/01_converging/trapping_rain_water.cpp
        05_sliding_window/29_fixed_size_window/permutation_in_string.cpp
        05_sliding_window/29_fixed_size_window/643_maximum_average_subarray_i.cpp
        05_sliding_window/29_fixed_size_window/find_all_anagrams_in_a_string.cpp
        05_sliding_window/30_variable_size_window/longest_repeating_character_replacement.cpp
        05_sliding_window/30_variable_size_window/minimum_window_substring.cpp
        06_stack/evaluate_reverse_polish_notation.cpp
        03_linked_list/19_inplace_reversal/reverse_linked_list_ii.cpp
        03_linked_list/19_inplace_reversal/reverse-nodes-in-kGroup.cpp
        12_dynamic_programming/generate_parenthesis.cpp
        03_linked_list/linkedList_Cycle_II.cpp
        15_design/96_general_design/LRUCACHE_2.cpp
        06_stack/38_largest_rectangle_histogram/largest_rectangle_in_histogram.cpp
        06_stack/Car_Fleet.cpp
        06_stack/implement_queue_using_stacks.cpp
        06_stack/implement_stacks_using_queue.cpp
        06_stack/BaseBallGame.cpp
        07_heap_priority_queue/39_top_k_elements/last_stone_weight.cpp
        07_heap_priority_queue/39_top_k_elements/k_closest_points_to_origin.cpp
        07_heap_priority_queue/car_pooling.cpp
        07_heap_priority_queue/39_top_k_elements/kth_largest_element_in_an_array.cpp
        07_heap_priority_queue/IPO.cpp
)
