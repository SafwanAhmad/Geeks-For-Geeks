/**This is a program implementing Linkbed List and all basic operations like insertion, deletion etc.
 * This program is implemented for problems available on Geeks for Geeks.
 */

#include<stdio.h>
#include<stdlib.h>


//void display(struct LinkedList *header);


struct LinkedList
{
    int data;
    struct LinkedList *nextNode;
};

struct LinkedList *header = NULL; //Initially there is no header, untill the list is initialized.

/**This method will intialize the linked list.
 * The header node will be assigned. This method is automatically called before
 * creation of the linked list.
 */

void initializeHeader()
{
    if(header == NULL)
    {
       header = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    }
}

/**This method will insert the node at the given postion.
 * Three possiblities can be there, 
 * 1. Insertion at the head. Denoted by H.
 * 2. Insertion at the tail. Denoted by T.
 * 3. Insertion in between head and tail. Denoted by B.
 */

void insertNewNode(struct LinkedList *header, const char position, int data, int afterData)
{
    switch(position)
    {
        case 'H':
        {
            printf("Adding node in the front\n");

            //Create the new node
            struct LinkedList *newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));

            //Enter the data
            newNode->data = data;

            //Update the Link
            newNode->nextNode = header->nextNode;

            //Update the header link
            header->nextNode = newNode;
        }
        break;
        case 'T':
        {
            printf("Adding the node at the tail\n");
            //Create a new node
            struct LinkedList *newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));

            //Update the data part
            newNode->data = data;

            //Reach the end of the list
            while(header->nextNode != NULL)
            {
                header = header->nextNode;
            }
            //Update the link
            header->nextNode = newNode;
            //Now Point the new node to null
            newNode->nextNode = NULL;
            
        }
        break;
        case 'B':
        {
            printf("Adding node in between first and last node\n");
            //Create a new node
            struct LinkedList *newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));

            //Update the data
            newNode->data = data;

            //Update the links
            while(header->data != afterData && header != NULL)
            {
                header = header->nextNode;
            }
            if(header != NULL)
            {
                //Update the links
                newNode->nextNode = header->nextNode;
                //Update the previuos link
                header->nextNode = newNode;
            }

        }
        break;
        default:
        {
            printf("Incorrect parameters\n");
        }
    }
}

/**This method deletes a node from the linked list, starting from the header.
 * The deletion can be done at three places-
 * 1. Deletion at the front.
 * 2. Deletion at the end.
 * 3. Deletion somewhere between.
 */
void deleteNode(struct LinkedList *header, int nodeToBeDeleted)
{
    struct LinkedList *temp;

    //Check if the required node is the first node in the list
    if(header->nextNode->data == nodeToBeDeleted)
    {
        //Update the links
        temp = header->nextNode;
        header->nextNode = temp->nextNode;
        free(temp);
        return;
    }

    //Otherwise it is an intermediate node
    while(header->nextNode->data != nodeToBeDeleted && header->nextNode != NULL)
    {
        header = header->nextNode;
    }
    if(header->nextNode != NULL)
    {
        temp = header->nextNode;
        header = temp->nextNode;
        free(temp);
    }
    
    //It is the last node to be deleted
    else if(header->nextNode == NULL && 
    {

}

//Driver program
int main()
{
    //Initialize the linked list
    //Header will be allocated now.
    initializeHeader();

    //Insert a new node at the front.
    insertNewNode(header, 'H', 1, -1);

    //Insert a new node at the tail.
    insertNewNode(header, 'T', 3, -1);

    //Insert a new node in between
    insertNewNode(header, 'B', 2, 1);

    //Display
    display(header);
}

//Display method
void display(struct LinkedList *header)
{
    while(header != NULL)
    {
        printf("%d\n",header->data);
        header = header->nextNode;
    }
}

