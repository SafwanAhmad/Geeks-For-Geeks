/**This program finds out the length of a linked list in two ways-
 * 1. Iterative method
 * 2. Recursive method
 * A paramerter is required to choose either one of them.
 *
 * For the iterative method the parameter is : I
 * For the recursive method the parameter is : R
 */

#include "LinkedListBasics.h"
#include "LengthLinkedList.h"

int LengthLinkedList(struct LinkedList* header, const char parameter)
{
    switch(parameter)
    {
        case 'I':
        {
            return FindLengthIterative(header->nextNode);
        }
        break;
        case 'R':
        {
            return FindLengthRecursive(header->nextNode);
        }
        break;
        default:
        {
            printf("Incorrect option selected for the length!\n");
        }
    }
}

static int FindLengthIterative(struct LinkedList *header)
{
    int length;

    while(header != NULL)
    {
        header = header->nextNode;
        length++;
    }
    return length;
}

static int FindLengthRecursive(struct LinkedList *header)
{
    if(header == NULL)
    {
        return 0;
    }
    else return (1 + FindLengthRecursive(header->nextNode));
}
