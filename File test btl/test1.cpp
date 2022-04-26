#include<iostream>
#include<sstream>
#include<math.h>
#include<string>
using namespace std;
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
        ss << "<Points[" << x << "," << y << "]>";
        return ss.str();
    };

    int distanceTo(const Point & otherPoint) const{

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
        
        this->head = NULL;
        this->tail = NULL;
        this->count = 0;
        this->length = -1;
    };
    
    ~Path(){ // ~Path() is the destructor
        //delete memory
        Node * current = head; //current is used to traverse the path
        while(current != NULL){
            Node * temp = current; //temp is used to delete the memory
            
            current = current->next;
            
            delete temp;
        }

    
    };

    void addPoint(int x, int y){
        
        //add (x,y) to the end of the path
        Node * newNode = new Node(Point(x,y));
        if(head == NULL){ //if the path is empty
            head = newNode; //add the new node to the head
            tail = newNode; //add the new node to the tail
        }
        else{ //if the path is not empty
            tail->next = newNode; //add the new node to the tail
            tail = newNode; //add the new node to the tail
        }

        count++;
        length++;
        if(count == 1){
            length = 0;
        }
        else if(count > 1){
            length = length + newNode->point.distanceTo(tail->point);
        }
        else if(count  == 0){
            length = -1;
        }



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
                ss <<"<Node[" <<current->point.toString();
            }
            current = current->next;
        }
        ss << "]>";
        return ss.str();
    

        

    };
    
    void getLength(){
        Node * current = head; //current is used to traverse the path
        while(current != NULL){
            
            if(current != tail){
                length = length + current->point.distanceTo(current->next->point);
            }
            current = current->next;
        }
    };

     

    Point getLastPoint() const{
        return tail->point;
    
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
        delete[] path; 
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
};



bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
        int l1 = chWatson.getPath()->getLength();
        int l2 = chMurderer.getPath()->getLength();
        bool check;
        int outDistancez ;
        if(l1-l2 <= maxLength){
            outDistancez = l1-l2;
            check = true;
        }
        else{
            outDistancez = -1;
            check = false;
        }
        

    return check;
}
int main(){
 
    Point p1(0, 5);
    cout << p1.toString() << endl;

    Point p2(9, 3);
    cout << p2.toString() << endl;


    Node node1 ( Point (1 , 2) ) ;
    Node node2 ( Point (2 ,3) , & node1 ) ;
    cout << " node 1:" << node1 . toString () << endl ;
    cout << " node 2:" << node2 . toString () << endl ;
    
    //MISSION 1 + 2: DONE

    Path path1;
    cout<<path1.toString()<<endl;
    path1.addPoint(0, 1);
    cout<<path1.toString()<<endl;
    path1.addPoint(1, 3);
    cout << path1.toString() << endl;
 
    //mission 3: DONE

    Character chWatson("Emma Watson");
    cout << chWatson.getName() << endl;

    chWatson . setName ("John Watson ") ;
 cout << chWatson . getName () << endl ;

    chWatson.moveToPoint(2, 7);
    cout << chWatson.toString() << endl;




    return 0;
}