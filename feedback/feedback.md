# Mentor Feedback

## Week 1: 11/06 - 11/12

There was no dev log for this week. Please make to complete the rest of the dev logs to get full points in this section. 

## Week 2: 11/13 - 11/26

### Serena's Feedback
Thank you for the update. 

In regards to your question, either way works to store your graph. Adjacency matrix may take more memory, but it will be fine for this application, especially since your largest dataset is only 250x250. Choose whichever you like -- an adjacency matrix may be simpler for this assignment. In real world applications, the decision would be made looking at the runtime and memory consumption of both implementations.

Please also make sure to schedule your mid project meeting soon. Let us know if you have any other questions!


### Blaine's Feedback

Hi team! To complete the project, I would focus on **implementing** code and ensuring that you pass your test cases. Then, if for some reason there is unwanted behavior, add a test case to address it. Additionally, it may be beneficial to get ahead of the curve for this project to allow some breathing room for other projects/final exams. To this end, I would like to see you guys write out some more goals along with granular explanations and subgoals. 

You can definitely do either representation (I prefer thinking about it as seen in [this video](https://www.youtube.com/watch?v=RVIr8Y5isek&ab_channel=PoloClubofDataScience)), but make a decision and justify it. Usually things come with tradeoffs - discuss these in your final report in terms of time and space complexity.

Lastly, keep documenting your progress and it will be helpful when you go to write the final report!

## Mid Project Meeting

We met for our Mid Project Meeting on 11/28 at 12pm. The team was able to present their algorithm with an explanation of how their tests would prove the algorithm's accuracy. 

We discussed the issue mentioned with the randomness of the random surfer model causing some tests to fail. One solution to this would be having a global epsilon to account for this error, and to mention that there is inherently a difference between the two models for calculating PageRank in your report. 

Overall, great job! 

## Week 3: 11/27 - 12/03

### Serena's Feedback
Great job making progress this week.

We discussed the issues encountered in our Mid Project Meeting and it has been summarized above. You both are on track to finish the project. Nice job outlining and finishing goals for this week. 

Let us know if you have any questions as you continue working on the remaining code and report. 

### Blaine's Feedback
Hi team! You guys are making great progress. One of the only TODOs left is to *explore how this randomness affects your algorithm* - through test cases and graphs with the epsilon parameter as we discussed prior if you so choose.

In your report, explore this strangeness. What is is causing this? How did a engineer at Google solve this problem in PageRank? (Honestly, I am curious! Clearly it would be in their best interest to serve the same ordered/ranked pages to everyone to be consistent). What would you do if you were Sergey Brin / Larry Page in the early days of Google and you came across this issue.

A plot of epsilon (e.g. how much error you are okay with) changes with input size N. You can also explore Big O() and Big Ω(). A lot of the time we worry about the worst case situation and prioritize reducing it. However, perhaps users hardly ever come across the worst case situation and instead the "average" case situation is close to the best case situation. If we make an expensive tradeoff to minimize O() versus Ω(), that may not be the best thing to do.

Either way, I have thrown out some ideas for you to explore. Feel free to email me if you want to discuss further or hop on a quick Zoom call!



## Week 4: 12/04 - 12/06

### Serena's Feedback

Great job on finishing the project! It looks like you were able to fix the epsilon issues you encountered. Grades will be in soon. Feel free to email us if you have any questions or concerns.
