# Ternary Tree
In this task, we will impelement [Ternary Tree](https://en.wikipedia.org/wiki/Ternary_tree) and generic [Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) in C language, using *dynamic allocations*.  

### Introduction
The Tern-ary family prepared well for Covid, so that each family member will meet at most four people:  
<p align="center">
  <img 
    width="350"
    height="170"
    src="https://user-images.githubusercontent.com/92651125/156370560-dff37be3-a1b3-4935-9715-e4b10a4687ea.png"
  >
</p>

Every family member has a name and ID, and ID number for two family members must be different.  
The ternary tree supports the following operations:  
1) Exit
2) Create a family
3) Add a family member
4) Print the family tree:  
    a) back to main menu  
    b) printing the family tree visually  
    c) printing the family in pre-order  
    d) printing the family in left-order  
    e) printing the family in BFS (using generic *queue*)  
5) Quarantine
6) Super-spreader
7) Vaccine
8) Reprint the menu  

If a dynamic allocation fails, the message ```Malloc Failed!``` is printed, and then all the allocated memory is released.  
<p align="left">
  <img 
    width="260"
    height="129"
    src="https://user-images.githubusercontent.com/92651125/156373388-fb2f45b3-0800-48ff-9694-0a81c27b5ea2.png"
  >
</p>

### Create a family
The creation of the family tree will only occur when there are no family members yet.  
If there are family members, the message ```The family has already been created``` in printed.  
Otherwise, the user will enter the name and ID of the head of the family, the family tree is created and the message ```Hello (name), ID: (ID)``` is printed.  
Then, we will allow to return to the main menu and the message ```Select the next operation (insert 7 for the entire menu):``` is printed.  

### Add a family member
First we get the ID of the family member who wants to make an appointment: ```Enter the ID of the person who wants to make an appointment```. If the family member exists, we will receive the name and ID of the new family member and add him to the family tree. If there is a problem with one of the inputs (the first ID does not exist, the new ID is already in use, the family member already has 3 appointments) an error message is printed.

### Printing the family tree
We will support four types of traversals: visual, pre-order, left-order, [BFS](https://en.wikipedia.org/wiki/Breadth-first_search) *using generic Queue*.  
I will give one example of the BFS print:  
The tree is:  
<p align="left">
  <img 
    width="300"
    height="191"
    src="https://user-images.githubusercontent.com/92651125/156385223-bbde4b83-75e7-47e3-924f-19733e1316b5.png"
  >
</p>

Output:  
<p align="left">
  <img 
    width="30"
    height="146"
    src="https://user-images.githubusercontent.com/92651125/156385614-3b70dfcf-43f0-4df1-8ac3-4e693bfc184f.png"
  >
</p>

> The generic queue is implemented in the queue.c file

### Quarantine
If there is a suspicion that one of the family members is infected with Covid, all direct contacts are placed in isolation: the father and all the meetings.  
From the previous example, if B is the suspected member the next message will be printed:  
```
‫!‪#StayHome‬‬ ‫‪A‬‬ ‫‪1‬‬
‫!‪#StayHome‬‬ ‫‪B‬‬ ‫‪2‬‬
‫!‪#StayHome‬‬ ‫‪C‬‬ ‫‪3‬‬
‫!‪#StayHome‬‬ ‫‪E‬‬ ‫‪5‬‬
‫!‪#StayHome‬‬ ‫‪F‬‬ ‫‪6‬‬
```
