This repository contains the source code of a C program that calls the kernels of an x86-64 and C to compute the dot product between two vectors. These two kernels are timed to measure their execution time. Shown below is the average exection time of the two kernels depending on the vector size.

Comparison of Execution Time When Vector Size = 2^20: x86-64: 0.0007333333333s  C: 0.003s
Comparison of Execution Time When Vector Size = 2^24 x86-64: 0.0117s            C: 0.04456666667s
Comparison of Execution Time When Vector Size = 2^30 x86-64: 0.7862666667s      C: 2.865633333s

Based on the analysis of execution times, it is evident that the kernel written in C for computing the dot product of two vectors exhibits notably slower performance compared to its x86-64 counterpart. This discrepancy becomes more pronounced with increasing vector sizes. As depicted in Table 1, the disparity in execution times between the C kernel and the x86-64 kernel becomes more conspicuous as the vector size grows. For instance, when the vector size is 2^24, the observed difference in runtime between the two kernels is 0.00227 seconds. This variance, though discernible, is relatively minor. However, as seen in Table 3, when the comparison is extended to much larger vector sizes, such as 2^30, the difference becomes substantial, reaching 2.079367 seconds. These findings underscore the efficiency gap between the C kernel and the x86-64 kernel, particularly under heavier computational loads, where the advantage of the x86-64 architecture becomes more evident.

The images below shows the screenshot of the program output of both kernels.
