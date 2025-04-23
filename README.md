Administrative
Wealth Sorters
David Shalshin (dshal20)
https://github.com/dshal20/Wealth-Sorters
https://www.youtube.com/watch?v=OoDAxM98dSc&ab_channel=DavidShalshin

Proposal
Problem: How can we efficiently sort and rank billionaires based on different attributes (net worth, age, source of wealth) using large-scale data sets? What sorting algorithm performs best for this task?
Motivation: Sorting is one of the most common data processing tasks taught. With over 100,000 randomly generated data points forming a billionaire data set, understanding which sorting algorithm performs better on large data sets can help in both practical and academic applications. This gives a more realistic take on sorting algorithms since data sets are typically very large outside of beginner classes.
Features implemented: The data set is allowed to be sorted using two different sorting algorithms. These algorithms will be displayed for the user to pick. After the algorithm is picked, the program allows the data set to be sorted by three different attributes. These attributes will include name, networth, and age. The program will use chrono from the c++ standard library to measure how long the algorithm takes to run. This will help the user compare times and what algorithm takes a shorter amount of time to run. The program will then output the sorted data onto a csv file. 
Description of data: The data I used for my project is randomly generated. It is a 100,000 data point of made up billionaires. Each billionaire has a name (string), age (int), net worth (double), country (string), and self made attribute (bool). The unsorted csv file can be found inside the cmake-build-debug folder.
Tools/Languages/APIs/Libraries used: I use a variety of tools for this project. To start off, I use c++ as the main language during this project. I also use the chrono standard library to keep track of algorithm times. I also use fstream and sstream to read and write on csv files. I end off by using a vector library so I can manipulate data points and effectively implement my sorting algorithms. 
Algorithms implemented: One algorithm implemented is merge sort. This is a divide and conquer algorithm that recursively splits the data set into halves. It then sorts them and merges them back together. Another algorithm implemented is quick sort. This is also a divide and conquer algorithm. This algorithm partitions the data set around a specific pivot and recursively sorts the arrays.
Additional Data Structures/Algorithms used: I used a vector to store the entire data set that is read from the data file.
Distribution of Responsibility and Roles: I did the entire project since there was no communication between my group. This is an individual project.

Analysis 
I changed my proposal from the original proposal in project 3a. This was mainly done because I was unable to generate the data set required for the original proposal. I decided to instead create a data set about billionaires with many types of variables. This would be a great way to compare divide and conquer sorting algorithms and see which one performs well in realistic, large data scenarios.
To start off, the merge sort algorithm had a worst case time complexity of O(n*logn). This is because the algorithm splits the data set into halves recursively, which takes O(logn) time. It then proceeds to merge them back which takes O(n). Combining these gives you the O(n*logn) time complexity. The quick sort algorithm has a worst case time complexity of O(n^2). This happens when the pivot is the smallest or largest element and the program is processing one element at a time. The readCSV() function has a time complexity of O(n) where n is the number of rows in the data set. 

Reflection
The overall experience was very unique and enjoyable. Both of these traits were due to the fact that I had a lot of freedom on what and how to code the program. It was very nice to not have a specific format to follow and have a lot of independent freedom when writing lines of code. I found it a bit challenging to create and think of which data set I will use and connect to a real world problem. Once I solved this issue, It was much easier to continue through with this project. If I was able to start again, I would definitely put my entire focus on finding a data set and a real world problem that I can connect to that data. I believe that I was focusing too strongly on which algorithm implementations I should use which resulted in a loss of time. I also would maybe code the project in python since it is more reader friendly and easier to work with. Lastly, I would maybe add in more features like the user being able to choose if they want the data in ascending or descending order. Throughout this entire project, I learned a couple new topics. I learned how to implement large data sets into a c++ program. I also used the chrono library for the first time and learned how to see an algorithm's run time. 

References
https://www.geeksforgeeks.org/quick-sort-algorithm/
https://www.geeksforgeeks.org/merge-sort/
https://corgis-edu.github.io/corgis/csv/billionaires/
