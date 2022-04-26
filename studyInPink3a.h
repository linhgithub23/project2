/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0){
        this->x = x;//this line is used to initialize the value of x
        this->y = y;//"this" is used to access the value of y

    };


    string toString() const{
        stringstream ss;
        ss << "<Point[" << x << "," << y << "]>";
        return ss.str();
    };

    int distanceTo(const Point & otherPoint) {

        int x1 = this->x;
        int y1 = this->y;
        int x2 = otherPoint.x;
        int y2 = otherPoint.y;
        double distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        return ceil(distance);
    };
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path; 

public:
    Node(const Point & point=Point(), Node * next=NULL){
        this->point = point;
        this->next = next;

    };

    
    string toString() const{
        stringstream ss;
        ss << "<Node[" << point.toString() << "]>";
        return ss.str();
    
    };
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    
    Path(){
        
       this-> head = nullptr;
        this->tail = nullptr;
        this->count =0;
        this->length=-1 ;
    };
    
    ~Path(){
        //delete memory
        head = nullptr;
        tail = nullptr;


    
    };
    void countNodes(){
        Node * current = head;
        while(current != NULL){
            count++;
            current = current->next;
        }
    };
   
    
    void addPoint(int x, int y){
        
        //add (x,y) to the end of the path
        Node * newNode = new Node(Point(x,y));
        if(head == NULL){ //if the path is empty
            head = newNode; //add the new node to the head
            tail = newNode;
            length = 0; 
            count = 0;//add the new node to the tail
        }
        else{ //if the path is not empty
           length += tail->point.distanceTo(Point(x,y)); //add the new node to the tail
            if(count==1) {
                head->next = newNode;
                }
                
            else {
                tail->next = newNode;
            }
            tail = newNode;
        
        }
        
        count++;


    };
    
    string toString() const{
       
        stringstream ss;
        ss << "<Path[count:" << count << ",length:" << length<<"," <<"[";
        Node * current = head; //current is used to traverse the path
        while(current != NULL){
            
            if(current != tail){
                ss <<"<Node[" <<current->point.toString()<<"]>,";
            
            }
            else{
                ss <<"<Node[" <<current->point.toString()<<"]>";
            }
            current = current->next;
            
        }
        ss<<"]]>";  
        return ss.str();
    

        

    };
    
    Point getLastPoint() {
        return tail->point;

    };
    int getLength() const{ //const is used to make the function read only
        return length;
    };
};
class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name=""){
        this->name = name;
        this->path = new Path();
    
    };
    ~Character(){
        name = "";
        path = nullptr;
    };
    
    

    string getName() const{
        return name;
    };
    

    void setName(const string & name){
        
        this->name = name;
    

    };
    

    void moveToPoint(int x, int y){
            
        path->addPoint(x,y);
    
    
    };
    string toString() const{
        
        stringstream ss;
        ss << "<Character[name:" << name << ",path:" << path->toString() << "]>";
        return ss.str();
    
    };
    int getPathLength() const{
        return path->getLength();
    };
    Point getCurrentPosition() const{
        return path->getLastPoint();
    };
};


bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
    int l1 = chWatson.getPathLength();
    int l2 = chMurderer.getPathLength();
    
    

    Point p1 = chMurderer.getCurrentPosition();
    Point p2 = chWatson.getCurrentPosition();
    if(l1 - l2 <= maxLength){
        outDistance = p1.distanceTo(p2);
        if (outDistance <= maxDistance) {
           return true;
        }
        return false;
        
    }
    else{
        outDistance = -1;
        return  false;
    }
        };



////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */