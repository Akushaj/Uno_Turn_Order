## 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?
= concat only works between two lists of same type because other comes in as a type List<T>* which can't see the private data_ or head_. Using dynamic_cast to turn it into my own type and if it returns null ptr it will print a message and return. To support both ArrayList and LinkedList together, I would have to move elements one at a time by creating nodes or copying pointers into the array instead of just moving what is already there.

## 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.
=  The pointers I used in reverse are prev ( the one who points at the node behind), current ( the node that is being flipped), next (the node ahead that hasn't been reached yet). I saved next first because the flipping current->next to point backword would be cut out from the rest of the list. If I lost prev there wouldnt be anything to point the current back to and if I lost current I would not be able to keep on moving.

## 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?
=  addAnywhere has a valid range of [0, size] because position == size means we need to append right after the last element. For deleteAnywhere the range is [0 , size-1] as there is no element at size to remove and an empty list has no element at all to remove. If the position is outside the range my code prints a message and returns without changing the list. 

## 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

## 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

## 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.