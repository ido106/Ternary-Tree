# Ternary Tree
In this task, we will impelement [Ternary Tree](https://en.wikipedia.org/wiki/Ternary_tree) and generic [Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) in C language, using *dynamic allocations*.  

### Introduction
The Ternari family prepared well for Covid, so that each family member will meet at most four people:  
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
Example:  
<p align="left">
  <img 
    width="350"
    height="243"
    src="https://user-images.githubusercontent.com/92651125/156376040-d6512d8b-cd41-40b0-9f46-205320107ae6.png"
  >
</p>

### Add a family member
First we get the ID of the family member who wants to make an appointment: ```Enter the ID of the person who wants to make an appointment```. If the family member exists, we will receive the name and ID of the new family member and add him to the family tree. If there is a problem with one of the inputs (the first ID does not exist, the new ID is already in use, the family member already has 3 appointments) error message is printed.
