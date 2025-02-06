import heapq
import math

# first put a box in each city 
# for the remaining boxes, put in the box
# where with current highest votes per box 

# use min heap -> make all the values negative so it functions as a max heap 

max_ballots = []

while (True):
    line = input()
    if not line: 
        print('', end='')
        break
    
    cities = int(line.split(" ")[0]) 
    boxes = int(line.split(" ")[1])

    # check proper conditions 
    if (cities < 0 or boxes < 0):
        print('', end='')
        break

    # create max heap of populations
    pop_arr = []

    # create array of boxes per city 

    # we've 'placed' a box in each city, so subtract that many boxes from total
    boxes -= cities; 

    # represents the max boxes in a city 
    # we start with 1 because every city must have a box 
    max_boxes = 1; 

    for i in range(cities):

        # inserting the tuple (curr votes per box in a city, boxes per city)
        pop_arr.append(((-1 * int(input())), 1));   # append inverse because we are using max heap 
    
    # this will ensure that we always pop the city with the current max ballots per box 
    heapq.heapify(pop_arr)

    # outer loop runs in n time, n = number of boxes
    # inner loop runs in logc time, c = number of cities 
    # runtime = nlogc 

    while (boxes > 0):  # until no more boxes left
        curr_largest = heapq.heappop(pop_arr);   # O(logn)

        votes = -1 * curr_largest[0]
        curr_boxes = curr_largest[1]

        # divide by another box 
        # round up 
        votes = (votes * curr_boxes) / (curr_boxes + 1)

        # we just added another box into the city with the max votes per box 
        curr_boxes += 1

        # decrement total boxes because we used another 
        boxes -= 1

        # add curr_largest back into heap
        heapq.heappush(pop_arr, (-1 * votes, curr_boxes))     # O(logn)

    max_ballots.append(math.ceil(-1 * heapq.heappop(pop_arr)[0]))

    # new line after 
    line = input()
    # if not line: 
    #     break



for output in max_ballots:
    print(output)






