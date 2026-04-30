cmake_minimum_required(VERSION 3.25)
project(cpp_dsa_thita)

set(CMAKE_CXX_STANDARD 17)
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
)
