#include <bits/stdc++.h>
using namespace std;

//Pairs
void explainPairs(){
    pair<int,int> p = {1,3};

    cout<<p.first<<" "<<p.second;

    pair<int, pair<int,int>> q ={1,{2,3}};

    cout<<p.first<<" "<<q.second.second<<" "<<q.second.first;

    pair<int,int> arr[] = {{1,2},{3,5},{4,6}};
    
    cout<<arr[1].second;

}

//printing vector
void printVec(vector<int>& nums){
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
}
//vector:- container it is

void explainVector(){
    vector<int> v; // vector declaration 
    //creates an empty container

    v.push_back(1); // inputs or adds value in the vector
    v.emplace_back(2); //same as above function but it increases the size dynamically and pushes the values

    vector<pair<int,int>> vec;
    
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v1(5,100);// here vector is declared of size 5 with  instane 100 on every index

    vector<int> v2(5); //here vector of size 5 is declared with each instance as 0
    vector<int> v3(5,20); //= {20,20,20,20,20}
    vector<int> v4(v3); // create the exact copy of v1 in different container
    vector<int>::iterator i= v3.begin();
    i++;
    cout<< *(i)<<" ";

    i = i+2;
    cout<< *(i)<<" ";

    vector<int>::iterator it = v2.end();
    // vector<int>::iterator i= v.rend();//reverse
    // vector<int>::iterator i= v1.rbegin();//reverse

    cout << v[0] <<" "<< v.at(0)<<" ";

    cout<< v.back()<<"\n";//last element

    //Priting vectors
    for(vector<int>::iterator it = v1.begin(); it !=v1.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    //shortcut printing
    for(auto it =v1.begin(); it != v1.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it : v){
        cout<< it <<" ";
    }
    cout<<endl;

    //easring a function or deleting a function 
    v1.erase(v.begin()+1);
    v1.erase(v1.begin()+2,v1.begin()+4);// if we want to erase upto a range we provide starting and ending address

    printVec(v1);

    //insert function

    v1.insert(v1.begin(),300);
    v1.insert(v1.begin()+1,2,10);// v.insert(position i wanna enter, count of no.s i wanna enter, no. which i wanna enter);
    
    printVec(v1);

    vector<int> copy(2,50);
    v1.insert(v1.begin(), copy.begin(), copy.end());
    printVec(v1);

    cout<<v1.size()<<endl; // .size is a function which calculates the size of the vector 
    

    v1.pop_back();// it pops out the last element 

    v1.swap(v2);// swap v1 with v2

    v.clear(); // erase the entire vector

    printVec(v);
}

void explainList(){
    //list are the containers and very similar to vectors differencce it give front operations as well

    list<int> ls;
    ls.push_back(2);//{2}
    ls.emplace_back(4); //{2,4}

    ls.push_front(5);//{5,2,4}

    ls.emplace_front();//{2,4}

    //rest functions are same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap

}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2}
    dq.emplace_front(3);//{3,4,1,2}

    dq.pop_back();  //{3,4,1}
    dq.pop_front(); //{4,1}

    dq.back();
    dq.front();

    //rest functions are same as vectors
    //begin, end, ebegin, rend, clear, insert, size, swap
    //tc for all operations is O(1)
}


void explainStack(){
    //based in LAST IN FIRST OUT

    stack<int> st;
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(3);//{3,3,2,1}
    st.emplace(5);//{5,3,3,2,1}

    cout<< st.top(); //prints 5 "** st[2] is invalid **"

    st.pop();// st looks like {3,3,2,1}

    cout<< st.top();

    cout<<st.size();//4

    cout<<st.empty();

    stack<int>st1, st2;
    st1.swap(st2);

    //push to enter a number
    //pop to remove a number
    //top is used to access the element on the top of the stack
    //tc for all operations is O(1)
}

void explainQueue(){
    // it is first in first out 
    queue<int> q;
    q.push(1);//{1}
    q.push(2);//{1,2}
    q.push(4);//{1,2,4}

    q.back() += 5; // add 5 to the last value in the queue

    cout<< q.back(); //prints 9

    //queque is {1,2,9}
    cout<< q.front();// prints 1

    q.pop(); //{2,9}

    cout<< q.front(); //prints 2

    //size swap empty same as stack
    //tc for all operatoins push pip etc is O(1)

}
void explainPriorityQ(){
    // the element withh the highest numbers stays at top

    priority_queue<int> pq;

    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2}

    cout<< pq.top(); //print 10

    pq.pop(); //{8,5,2}

    cout<< pq.top(); //prints 8

    //size swap empty functions same as others

    //minimum heap or minimum pq
    priority_queue<int ,vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.push(8); //{2,5,8,10}

    cout << pq.top(); //prints 2
    //tc for push and pop -> log n
    //tc for top-> O(1)
    
}

void explainSet(){
   // set is a collectionn which stores everything in the sorted order
   // it stores everything unique

   set<int> st;
   st.insert(1);//{1}
   st.insert(2);//{1,2}
   st.insert(2);//{1,2}
   st.insert(3);//{1,2,3}
   st.insert(4);//{1,2,3,4}

   //functionnality of insert in vector
   //can be used also, that only increases
   // the efficiency 

   //begin(),end(), rbegin(), rend(), size()
   //empty() and swap() are same as those of above


   //FIND points to the address of the element

   //example:{1,2,3,4,5}
   auto it = st.find(3); // here it is the iterator and "it" points to the address fo the result
   //ex

   auto it = st.find(6); // if we find a no. that is not present in set
   // in return it gives st.end() here IT point afterward of the last element 

   //erase or delete
   st.erase(5); //erases 5 //it takes log n time

   int count = st.count(1); // a number exist it gives 1 count and it not it givs 0

   auto it = st.find(3);
   st.erase(it); // it takes constant time 

   //ex:{1,2,3,4,5}
   auto it1 =st.find(2);
   auto it2 = st.find(4);
   st.erase(it1,it2); // after erase {1,4,5} it works like [first,last)

   //lower_bound() and upper_bound() function works in the same way
   // as in vector it does

   //This is the syntax
   auto it = st.lower_bound(2);
   auto it = st.upper_bound(3);       
}

void explainMultiSet(){
    //everythinng is same a set
    // only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}
    ms.insert(1);//{1,1,1,1}

    ms.erase(1); // all 1's are erased

    int cnt = ms.count(1); // counts the no. of one's in the mulitset

    //only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(3));
    // rest all function are same a sset
}

void explainUnsortedSEt(){
    unordered_set<int> st;
    // it exacttly same as set just it does not store the elements in the sorted order
    //lower_bound and upper_bound function
    //does not works, rest all functions are same
    //as above, it does not stores in any 
    //particular order it has a better complexity
    //than set in most cases, except some when collision happens
    // in most of the concept TC is O(1) for all operation
}
 
void explainMap(){
    //map stores unique keys in the sorted order 

    map<int, int> mpp;
    map<int, pair<int,int>> mpp;
    map<pair<int,int>, int>mpp;

    // in each of the above the first varaible is key and the second varaible is the value which the key points 


    mpp[1]=2;
    mpp.emplace(3,1);
    mpp.insert({2,4});

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second <<endl;
    }

    //acceessing
    cout<<mpp[1];// gives 2
    cout<<mpp[5]; // since it does not exist gives 0

    auto it = mpp.find(3); // it is used to find the iterator 
    //cout<<*(it).second;

    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    //erase, swap, size, empty are same as above   

}

void explainMultiMap(){
    //everythingn same a smap, only it can store multiple keys
    //onnly mapp[key] cannot be used here
}

void explainUnorderedMap(){
    //same as set and unordered_set difference.
}

int main(){

    explainVector();


}