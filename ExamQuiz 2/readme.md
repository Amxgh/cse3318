# Asymtotic Notation
- Θ is equal to/proportional to. *Asymptotic Tight Bound*
    -  I have one million dollars.
- O is less than or equal to. *Asymptotic Upper Bound (Can be tight)*
    -  I have at most one million dollars (You can also have exactly one million dollars). 
- Ω is greater than or equal to. *Asymptotic Lower Bound (Can be tight)*
    -  I have at least one million dollars (You can also have exactly one million dollars). 
- o is less than. *Asymptotic Upper Bound (Can* **NOT** *be tight)*
    -  I have at most one million dollars. 
- ω is greater than. *Asymptotic lower Bound (Can* **NOT** *be tight)*
    -  I have at least one million dollars. 


- If something is Θ(X), it is also O(X) and Ω(X)

# Sorting
**Stable:** Relative positions remain the same after a sort. If there are two equal elements, it won't reorder them. 
Assuming the array is:

| 12 | 50 | 37 | 19 | 50 | 17 |
|----|----|----|----|----|----|
| A  | B  | C  | D  | E  | F  |

After sorting, it becomes:
| 12 | 17 | 19 | 37 | 50 | 50 |
|----|----|----|----|----|----|
| A  | F  | D  | C  | B  | E  |
The above is stable sort. 

Unstable sort would be:
| 12 | 17 | 19 | 37 | 50 | 50 |
|----|----|----|----|----|----|
| A  | F  | D  | C  | E  | B  |

So here, for stable sort B came before E because that's how it was in the array when the array started.

**Adaptive:** An algorithm is adaptive if a partially sorted array is sorted quicker than an unsorted array. 
Adaptive Algorithms:
- Insertion

**Direct:** Modifies the original data in place. Moves items as needed

**Indirect:** Does not modify the original data in any way. An algorithm is indirect if it uses extra space to sort.
    - Applications: 
        - Sorting arrays of large objects
        - Used if no permission to modify original array
    - Solution: 
        - In the final array, you keep the indexes of the sorted elements in the original array.
  



## Bucket Sort
- Stable
- Not Adaptive


**Space Complexity:** *O(n+k)* where n is the number of elements and k is the number of buckets. 

**Time Complexity:**

    Best Case: O(n+k)

    Worst Case: O(n^2)


- Formulas for computing the index:
    - If numbers in the array are between [0, 1) use:
        - index = floor(elem*N)
    - General formula:
        - index = floor((elem-min)*N/(1+max-min))

## Insertion Sort
- Stable
- Adaptive


**Space Complexity:** *O(1)*

**Time Complexity:**

    Best Case: O(N)

    Worst Case: O(N^2)

## Count Sort
- Stable
- Not Adaptive


**Space Complexity:** *O(n+k)*  where n is the number of elements and k is the range of distinct values. 

**Time Complexity:**
    
    Best Case: O(n+k)
    
    Worst Case:O(n+k)

## Radix Sort
- Stable
- Not Adaptive
- Can be used for sorting strings


**Space Complexity:** *O(n+k)*  where n is the number of elements and k is the range of distinct values.

**Time Complexity:**
    
    Best Case: O(nk)
    
    Worst Case: O(nk)
