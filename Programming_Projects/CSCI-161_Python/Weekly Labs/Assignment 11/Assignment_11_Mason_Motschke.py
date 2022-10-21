'''
Mason Motschke
CSCI 161
Thursday Lab 5-7
Program #11: Intertion Sort
'''
def InsertionSort(List, SortedList):
    if (List != []): #As long as list isn't empty do the following
        currListItem = List[int(len(List)/2)]; i = 0 #sets currItem in List + index start at 0
        if (SortedList == []): #Base case if SortedList is empty
            SortedList.append(currListItem)
            List.remove(currListItem) #Appends item to Sorted List and removes item from original list
        else:
            currSortItem = SortedList[i] #sets currItem in SortedList
            for x in range (len(SortedList) + 1):
                if (currListItem < currSortItem): 
                    SortedList.insert(i, currListItem)
                    List.remove(currListItem); break #Appends item to Sorted List and removes item from original list
                elif (currListItem > currSortItem):
                    try:
                        i += 1 #Increments index of SortedList
                        currSortItem = SortedList[i] #sets currSortItem
                    except: #Happens if index is out of bounds meaning last item in list for SortedList
                        SortedList.append(currListItem)
                        List.remove(currListItem); break #Appends item to Sorted List and removes item from original list
        InsertionSort(List, SortedList) #Calls itself with updated lists
    return #returns if List is empty

def main():
    ListToBeSorted = [22, 64, 11, 34, 25, 90, 12]
    EmptyList = []
    InsertionSort(ListToBeSorted, EmptyList)
    print("Sorted List: {0}".format(EmptyList))

main()