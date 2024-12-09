#include <iostream>
#include <string>

using namespace std;

// Cutie Interface
class Cutie {
public:
    virtual string description() = 0;    
    virtual int cuteness_rating() = 0;  
    virtual ~Cutie() {}
};

// Example implementations of Cutie objects
class Puppy : public Cutie {
public:
    string description() override {
        return "A tea cup puppy with big, sad eyes";
    }
    int cuteness_rating() override {
        return 11; 
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A fluffy kitten with a tiny pink nose";
    }
    int cuteness_rating() override {
        return 10;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny monkey with a graceful grin";
    }
    int cuteness_rating() override {
        return 9;
    }
};

// QueueTees class
class QueueTees {
private:
    Cutie** queue; // Array of pointers to Cutie objects
    int maxSize;   // Maximum size of the queue
    int front;     // Index of the front of the queue
    int rear;      // Index of the rear of the queue
    int count;     // Current number of elements in the queue

public:
    // Constructor
    QueueTees(int size = 10) : maxSize(size), front(0), rear(-1), count(0) {
        queue = new Cutie * [maxSize];
    }

    // Destructor
    ~QueueTees() {
        delete[] queue;
    }

    // Enqueue method
    void enqueue(Cutie& obj) {
        if (count == maxSize) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        queue[rear] = &obj;
        count++;
    }

    // Dequeue method
    Cutie* dequeue() {
        if (count == 0) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return nullptr;
        }
        Cutie* obj = queue[front];
        front = (front + 1) % maxSize;
        count--;
        return obj;
    }

    // Clear method (extra credit)
    void clear() {
        front = 0;
        rear = -1;
        count = 0;
        
    }
    
    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }
};


int main() {
    // Create Cutie objects
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    // Create a QueueTees instance
    QueueTees queue;

    
    cout << "Initial queue size: " << queue.size() << endl;

    
    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    
    cout << "Queue size after enqueuing 3 cuties: " << queue.size() << endl;

    
    Cutie* cutie = queue.dequeue();
    if (cutie) {
        cout << "Dequeued: " << cutie->description() << " (Cuteness rating: " << cutie->cuteness_rating() << ")" << endl;
    }

    cutie = queue.dequeue();
    if (cutie) {
        cout << "Dequeued: " << cutie->description() << " (Cuteness rating: " << cutie->cuteness_rating() << ")" << endl;
    }

    // Use the clear method (extra credit) 
    queue.enqueue(marmoset);
    cout << "Queue size before clear: " << queue.size() << endl;
    queue.clear();
    cout << "Queue size after clear: " << queue.size() << endl;

    // Attempting to dequeue from an empty queue
    queue.dequeue();

    return 0;
}
