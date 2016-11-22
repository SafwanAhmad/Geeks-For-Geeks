#ifndef LINKEDLISTBASICS_H
#define LINKEDLISTBASICS_H
#include<stdio.h>
#include<stdlib.h>



struct LinkedList
{
    int data;
    struct LinkedList *nextNode;
};


extern void initializeHeader();
extern void insertNewNode(struct LinkedList *header, const char position, int data, int afterData);
extern void deleteNode(struct LinkedList *header, int nodeToBeDeleted);
extern void display(struct LinkedList *header);

#endif
