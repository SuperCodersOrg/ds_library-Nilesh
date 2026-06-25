# Date - 2026-06-24 (Session 2)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 12:00pm to 1:15 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "LinkledList: clear() method bug fixed" </span> </span> </div>

### LinkedList

* Implemented copy assignment 
* clear()

### bug encountered 
``` cpp
template<typename T> void LinkedList<T>:: clear(){
    
    while(head){ 
        Node*temp=head; 
        temp=temp->next;  // head is never updating
        delete head; // wrong delete
    }
    head=nullptr;
    tail=nullptr;
    size=0;
}
```
Corrected version

```cpp
template<typename T> void LinkedList<T>:: clear(){
    
    while(head){
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    head=nullptr;
    tail=nullptr;
    size=0;
}

```

