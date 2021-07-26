
# KNAPSACK PROBLEM

It is very important problem in Dynamic Programming because this can be used to solve many DP problems.If we identify the problem as knapscak then solving them is pretty much easy task.So lets see how this single problem yield multiple variations and how to solve them.
  
INPUT :

- Items Array
- Profit [if any]
- Capacity of bag
  
## CLASSIFICATION OF KNAPSACK

Knapsack can be combination of both of the below types.

- Classification Based on part of an instance
    1. Fractional Knapsack
        - We can pick a part of an item,for example if we have an item with weight 3kg,I can take 1kg if an item and fill it up in the bag.
        - This problem can be solved using GREEDY METHOD,find the cost/profit for single part of each item and take item with max profit.
    2. Integer/Non-Fractional Knapsack
        - Here we should include the complete item,we cant take a part of it.

- Classification Based on number of instances
  1. 0/1 Knapsack
      - The item is either included or excluded.
      - What does it also mean?
        - Only one instace of item can be included,Or else no item is included.
  2. Bounded Knapsack
     - Here we can include the item or exclude it.
     - And We any include it atmost 'k' times,Not more than that.
          NOTE: 0/1 knapsack is a bounded knapsack with k=1.
  3. Un-bounded Knapsack
      - Here we can include the item or exclude it.
      - We can include any number of instance we can,no limit on number of instances.

## DYNAMIC PROGRAMMING OF KNAPSACK

So there are these many variations and constrints in knapsack , then how we can solve it.How these all questions can be solved using one method?
That is the power of dynamic programming, We can solve a large class of this problems using DP.If you notice , the commonalites of all these variations of knapsack.
    <pre><b> The item can be either included / excluded </b></pre>

This is the key for solving all variations of knapsack problems.YOu can either include it or exclude it.So there are only two desicions are possible.If we draw
a desicion tree, then we can understand that we need to calculate nearly evey possible way to find the solution.
So the time complexity that we can see from desicion tree is O(2^n).
Example : Items : [ 1, 2, 3 ]
Possible selections :
[] -> No item selected
[1 ] ->Only one item
[2 ]
[3 ]
[1 ,2 ] -> two item
[2 ,3 ]
[3 ,1]
[1 ,2, 3] -> all item

In terms of combination ,
So for three items , we can select atmost all.
3C0 + 3C1 + 3C2 + 3C3 = 8.

## POSSIBLE CONSTRAINTS FROM THIS QUESTION

Now we made our point.Of all these variations and classification,we end up in doing only one thing.***We either Include it or Exclude it***. So, when we wanna include or exclude depends on the questions,the possible constraints are :

1. Conditions on Profit
    - Sometimes cost of the items will be given,in such case you need to find the minimum cost on including.
    - Sometimes no profit or costs are given , then consider all are of same cost.
2. Conditions on weight
    - ***MANDATORY CONDITION : Common condition you cant exceed the capacity.***
    - You may need not to fill the bag completely,may be less is fine.
    - You should fill the bag completely.

## Knapsack Variation Problems

- Subset Sum PRoblem
- Partition equal subset sum
- Count of subsets with sum = x
- Partition a set into 2 subsets such that difference of substy sum is minimum
- Target Sum

## How to identify the Knapsack?

Example : Subset Sum Problem.
    Given a set of elements and sum find if the subset of the set can have addition value=sum.
    Array : [ 1 , 5 , 6 , 3 ]
    Sum   : 8
How this falls under the knapsack?
    WEIGHT/CAPACITY of the sack
    - Here the weight/capacity if the Knapsack is 8.
    - The items to be included must be exactly fill the bag not less not more.
    ITEMS CHOICE :
    - Since we are asked to find a 'subset' the number of times you select an item to fill is one.
    VALUES OF ITEMS :
    - In this problem , we consider the value of all items are equal.
