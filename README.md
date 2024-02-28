### Date
# Design a class called Date. The class should store a date in three integers: month, day, and year. There 
should be member functions to print the date in the following forms:
    12/25/10
    December 25, 2010
    25 December 2010

# Demonstrate the class by writing a complete program implementing it.

# Input Validation: Do not accept values for the day greater than 31 or less than 1. Do not accept values 
for the month greater than 12 or less than 1.


## To incorporate shallow and deep copy concepts into the Date class:

#     Shallow Copy Condition:
                    Since the Date class only contains primitive data types (int), shallow copying is 
    sufficient. You can rely on the default copy constructor and assignment operator provided by the 
    compiler, as they perform shallow copies effectively for primitive data types.
#     Deep Copy Condition: 
                    If the Date class had a member that involved dynamic memory allocation (e.g., 
    storing the date as a dynamically allocated string), you would need to implement a deep copy 
    constructor and assignment operator to ensure proper copying of dynamically allocated resources.


## Date Class Modification
                    Modify the Date class. The new version should have the following overloaded operators:
#     ++ Prefix and postfix increment operators. These operators should increment the object’s day member. 
#     -- Prefix and postfix decrement operators. These operators should decrement the object’s day member. 
#     - Subtraction operator. If one Date object is subtracted from another, the operator should give the 
    number of days between the two dates. For example, if April 10, 2010 is subtracted from April 18, 2010, 
    the result will be 8.


## << cout’s stream insertion operator. This operator should cause the date to be displayed in the form 
April 18, 2010


## >> cin’s stream extraction operator. This operator should prompt the user for a date to be stored in a 
Date object.


## The class should detect the following conditions and handle them accordingly:

 
         When a date is set to the last day of the month and incremented, it should become the first day 
        of the following month.
         When a date is set to December 31 and incremented, it should become January 1 of the 
        following year.
         When a day is set to the first day of the month and decremented, it should become the last day 
        of the previous month.
         When a date is set to January 1 and decremented, it should become December 31 of the 
        previous year