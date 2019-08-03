#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*start = NULL;

int main(){

int n,x,chc,ch=1,loc,locd;
char con,u='y';

// THIS PROGRAM OFFERS EVERY BASIC FEATURE OF LINKED LIST
// YOU CAN SEE ALL THE FEATURES IN THE MENU

while(ch!=13){
printf("ENTER THE CHOICE \n\n ******** ENTER 1 TO ENTER THE NEW ELEMENT ******* \n");
printf("******** ENTER 2 TO DISPLAY THE ELEMENTS ******* \n");
printf("******** ENTER 3 TO INSERT A NEW ELEMNT AT THE BEGINING ******* \n");
printf("******** ENTER 4 TO INSERT A NEW ELEMNT AT THE END ******* \n");
printf("******** ENTER 5 TO INSERT A NEW ELEMNT AT ANY LOCATION******* \n");
printf("******** ENTER 6 TO DELETE A ELEMNT FROM THE BEGINING******* \n");
printf("******** ENTER 7 TO DELETE A ELEMNT FROM THE END***** \n");
printf("******** ENTER 8 TO DELETE A ELEMNT FROM THE ANY LOCATION***** \n");
printf("******** ENTER 9 TO DELETE AFTER A GIVEN ELEMNT***** \n");
printf("******** ENTER 10 TO INSERT AFTER A GIVEN ELEMNT***** \n");
scanf("%d", &chc);
switch (chc){

case 1:
printf("ENTER THE ELEMENT\n");
scanf("%d", &x);
create(x);
break;

case 2:
display();
break;

case 3:
printf("ENTER THE ELEMENT\n");
scanf("%d", &x);
insert_begin(x);
break;

case 4:
printf("ENTER THE ELEMENT\n");
scanf("%d", &x);
insert_end(x);
break;

case 5:
printf("ENTER THE ELEMENT\n");
scanf("%d", &x);
printf("ENTER THE POSITION WHERE YPU WANT TO ENTER THE ELEMNT\n");
scanf("%d", &loc); 
insert_any(x,loc);
break;

case 6:
delete_beg();
break;

case 7:
delete_end();
break;

case 8:
printf("ENTER THE POSITION FROM WHERE WANT TO DELETE THE ELEMNT\n");
scanf("%d", &loc); 
delete_any(loc);
break;

case 9:
printf("ENTER THE NUMBER AFTER WHICH YOU WANT TO DELETE THE ELEMENT\n");
scanf("%d", &x);
delete_after(x);
break;

case 10:
printf("ENTER THE NUMBER AFTER WHICH YOU WANT TO ENTER THE ELEMENT\n");
scanf("%d", &locd);

printf("ENTER THE ELEMENT\n");
scanf("%d", &x);

insert_after(x,locd);
break;

default: printf("WRONG INPUT\n");

}

printf("DO YOU WANT TO CONTINUE\n");
printf("IF YES THEN ENTER Y IF NO THEN ENTER N\n");
scanf(" %c", &con);
if(con!=u)
break;
}
}

// THIS FUNCTION CREATES A NODE

void create(int x){

struct node *ptr, *temp;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = x;
ptr->next = NULL;
if(start == NULL){
start = ptr;
}
else{
temp = start;

    while(temp->next!=NULL){
    temp = temp->next;
    }
    
    temp->next = ptr;
}
}

// THIS FUNCTION PRINTS THE LINKED LIST

void display(){
struct node *temp;
temp = start;
printf("THE LINKED LIS AS FOLLOWS:\n");

if(start == NULL){
printf("LIST IS EMPTY\n");
}
else{
while(temp!=NULL){
printf("%d\n", temp->data);
temp = temp->next;
}
}
}

// THIS FUNCTION INSERTS A NODE IN THE BEGINING OF THE LINKED LIST

void insert_begin(int x){

struct node *ptr;
ptr = (struct node*)malloc(sizeof(struct node));

ptr->data = x;
ptr->next = start;
start = ptr;
}

// THIS FUNCTION INSERTS A NODE IN THE LINKED LIST

void insert_end(int x){

struct node *ptr, *temp;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = x;
ptr->next = NULL;
if(start == NULL){
start = ptr;
}
else{
temp = start;

    while(temp->next!=NULL){
    temp = temp->next;
    }
    
    temp->next = ptr;
}
}

// THIS FUNCTION INSERTS A NODE AT ANY LOCATION AS PER USER CHOICE

void insert_any(int x,int loc){
struct node *ptr, *temp;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = x;

if(loc == 0){
ptr->next = start;
start = ptr;
}
else{
temp = start;
    
    for(int i=0;i<(loc-1); i++){
    temp = temp->next;
    }
    
    if(temp == NULL){
    printf("LOCATION NOT FOUND\n");
    }
    else{
    ptr->next = temp->next;
    temp->next = ptr;
    }
}
}

// THIS FUNCTION DELETES A NODE FROM THE BEGINING OF THE LINKED LIST

void delete_beg(){

struct node *temp;
if(start == NULL){
printf("LIST IS EMPTY\n");
}
else{
temp = start;
start = start->next;
free(temp);
}
}

// THIS FUNCTION DELETS THE NODE FROM THE END OF THE LINKED LIST

void delete_end(){

struct node *temp, *prev;

if(start == NULL){
printf("LIST IS EMPTY\n");
}
else{
temp = start;
while(temp->next!=NULL){
prev = temp;
temp = temp->next;
}
prev->next = NULL;
free(temp);
}
}

// THIS FUNCTION DELETES THE NODE FROM ANY LOCATION AS PER USER CHOICE

void delete_any(int pos){

struct node *temp, *t1;

if(start == NULL){
printf("LIST IS EMPTY\n");
}
else{
temp = start;
if(pos == 0){
delete_beg();
}
else{
for(int i =0;i<(pos-1);i++){
temp = temp->next;
}

if(temp == NULL){
printf("LOCATION NOT FOUND\n\n");
}
else{
t1 = temp->next;
temp->next = t1->next;
free(t1);
}
}
}
}

// THIS FUNCTION DELETES THE NODE AFTER A GIVEN ELEMENT AS PER USER CHOICE

void delete_after(int y){

struct node *temp,*t1;

temp = start;

if(start == NULL){
printf("LIST IS EMPTY\n");
}
else{

while(temp->data!=y && temp!=NULL){
temp = temp->next;
}

if(temp == NULL){
printf("NUMBER IS NOT PRESENT \n\n");
}
else{
t1 = temp->next;
temp->next = t1->next;
free(t1);
}
}
}

// THIS FUNCTION INSERTS A NEW NODE AFTER A GIVEN ELEMENT AS PER USER CHOICE

void insert_after(int x,int y){
struct node *ptr, *temp, *p;

ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = x;
ptr->next= NULL;
temp = start;

while( temp->data!=y && temp!= NULL){
temp = temp->next;
}
if(temp == NULL){
printf("DATA NOT FOUND\n\n");
}
else{
p = temp->next;
temp->next = ptr;
ptr->next = p;
}
}





