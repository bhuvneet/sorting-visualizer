# sorting-visualizer

This Sorting Visualizer project leverages C++ with SLD2 library. It provides an interactive visualization of various sorting algorithms, making them easy to understand.

<b>Features:</b>
<b>Interactive Visualization</b>: The Sorting Visualizer demonstrates the array being sorted following the selected sorting algorithm

<b>Multiple Algorithms</b>: The user can choose from the below algorithms to visualize the array being sorted

<b>Array Size</b>: The size of the array can be modified between 20 to 2000. The lower and upper cap to the number of elements is to ensure that the sort is visualized in a smooth manner and is easy to follow



https://github.com/bhuvneet/sorting-visualizer/assets/78770635/f1eb4d68-515d-4a7f-8dda-6783047a9d06



<b>Getting Started:</b>
- Build the project: ./output/sorting-visualiser <sorting algorithm> <size of array>
  
- Run the project using the following accepted command line arguments: sorting algorithms
-   1: Bubble sort
-   2: Bucket sort (work-in-progress)
-   3: Selection sort
-   4: Insertion sort
-   5: Heap sort (work-in-progress)
-   6: Quick sort
-   7: Merge sort

- Observe the randomly generated array being sorted using SDL2 graphics

<b>Upcoming features (work-in-progress):</b>
- Compare two algorithms
- Time sorting algorithms using C++'s chrono library to understand the time complexity
- Use threads to separate UI and worker methods
