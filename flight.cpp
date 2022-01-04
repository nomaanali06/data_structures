#include<iostream>
#include<string>
#include<fstream>
#include <sstream>


using namespace std;


struct node
{
	
string name;
string date;
string departure_time;
string arrival_time;
string cost;
string flight;
string hotelfair;

node *next;

node(string source)
{
	name=source;
	next=NULL;
	date="";
       departure_time="";
      arrival_time="";
      cost="";
       flight="";
       hotelfair="";
}

node(string destination,string dte,string d_t,string a_t,string cst,string flt ){
	name=destination;
	   date=dte;
       departure_time=d_t;
      arrival_time=a_t;
      cost=cst;
       flight=flt;
	next=NULL;
}

};


int index=0;
node *array[10];
void initilize(){
	for(int i=0 ;i<10; i++)
	{
		array[i]=NULL;
	}
}



int search(string src){

	for(int i=0; i<index; i++)
	{
		if(array[i]->name==src)
		return i;
}
	return -1;
		
}



void source_insert(string abc){
	
	int search_temp;
	if(index==0){
		array[index]=new node(abc);
		index++;
	//	cout<<abc<<" inserted at "<<index<<endl;
	}
	else{
		search_temp=search(abc);
	//	cout<<"value received "<<search_temp;
		if(search_temp==-1){
		array[index]=new node(abc);	
		index++;
		}
		else{
		//	cout<<"same source received "<<endl;
		}
		
		
	}
	
	
}



insert(int indx, node* nd){
	if(array[indx]->next==NULL){
		array[indx]->next=nd;
	}
	else{
		node* ptr=array[indx]->next;
		
		while(ptr->next!=NULL)	{
			ptr=ptr->next;
		}
		ptr->next=nd;
	}
	
	
}

 int string_to_int(string s){
   char converted_string[7];
    int ii=0;
    for(int i=0 ;s[i]!='\0';i++){
    	if((s[i]=='0')or(s[i]=='1')or(s[i]=='2')or(s[i]=='3')or(s[i]=='4')or
    	(s[i]=='5')or(s[i]=='6')or(s[i]=='7')or(s[i]=='8')or(s[i]=='9')){
    		converted_string[ii]=s[i];
    		ii++;
		}
	}
    stringstream geek(converted_string); 
    int x = 0; 
    geek >> x; 
  
          return x;
	 }



//
//void path(string src, string dst){
//	int src_index;
//	src_index=search(src);
//	cout<<array[src_index]->name<<endl;
//	node* ptr=array[src_index]->next;
//		while(ptr!=NULL){
// 	  if(ptr->name==dst){
// 	  		cout<<"--"<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
// 	           
//	   }
//
//	   ptr=ptr->next;
//	 }
//	 
//	 
//}	 


void  minimum_price_path(string src, string dst){
	int src_index;
	int temp2=0;
	int fares;
	src_index=search(src);
	cout<<"source is "<<array[src_index]->name<<endl;
	node* ptr=array[src_index]->next;
		while(ptr!=NULL){
 	  if(ptr->name==dst){
 	  	fares=string_to_int(ptr->cost);
 	  	if(fares>temp2){
 	  		ofstream myfile;
 	  			  myfile.open ("minimumfare.txt");
   
myfile<<array[src_index]->name<<" "<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
		  myfile.close();
		  temp2=fares;
		   }
 	  	 else	if(fares==temp2){
 	  		ofstream myfile;
 	  			  myfile.open ("minimumfare.txt",ios::app);
   
myfile<<array[src_index]->name<<" "<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
		  myfile.close();
		  temp2=fares;
		   }
 
	   }

	   ptr=ptr->next; 
	 }
	 
	 
	 
char word[7][10];
	  string input;
    ifstream in;
    string lastinserted;
    string insert_input;
    cout<<" minimum fare calculated for given condition is : "<<endl;
 in.open("minimumfare.txt",ios::in);
 while(in){
 //	cout<<"open file"<<endl;
 		getline(in,input);
 	cout<<input<<endl;
	
 		
		 }
		 

        
in.close();	 
	 
	 	
}





void   minimum_time_path(string src, string dst){
	int src_index;
	int temp2=23423424;
	int fares;
	src_index=search(src);
	cout<<"source is "<<array[src_index]->name<<endl;
	node* ptr=array[src_index]->next;
		while(ptr!=NULL){
 	  if(ptr->name==dst){
 	  	fares=string_to_int(ptr->cost);
 	  	if(fares<temp2){
 	  		ofstream myfile;
 	  			  myfile.open ("minimumtime.txt");
   
myfile<<array[src_index]->name<<" "<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
		  myfile.close();
		  temp2=fares;
		   }
 	
 
	   }

	   ptr=ptr->next; 
	 }
	 
	 
	 
char word[7][10];
	  string input;
    ifstream in;
    string lastinserted;
    string insert_input;
    cout<<" nearest date of flight  calculated for given condition is  : "<<endl;
 in.open("minimumtime.txt",ios::in);
 while(in){
 //	cout<<"open file"<<endl;
 		getline(in,input);
 	cout<<input<<endl;
	
 		
		 }
		 

        
in.close();	 
	 
	 	
}





void path(string src, string dst){
	int src_index;
	src_index=search(src);
	cout<<"{source}"<<array[src_index]->name<<endl;
	node* ptr=array[src_index]->next;
		while(ptr!=NULL){
 	  if(ptr->name==dst){
 	  
 	cout<<"-destination-"<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
 	        
	   }

	   ptr=ptr->next; 
	 }
	 
	 
}





void date_path(string src, string dst, string dte){
	int temp1=0;
	int src_index;
	src_index=search(src);
	cout<<"{source is}"<<array[src_index]->name<<endl;
	node* ptr=array[src_index]->next;
		while(ptr!=NULL){
 	  if((ptr->date==dte)and(ptr->name==dst)){
 	  
 	cout<<"-destination-"<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
 	      temp1++;  
	   }

	   ptr=ptr->next; 
	 }
	 if(temp1==0){
	 	cout<<"sorry no path found on specific date :("<<endl;
	 	cout<<"below are available options "<<endl<<endl<<endl;
	 	path(src,dst);
	 }
	 
}




void flight_path(string src, string dst, string flt){
	int temp1=0;
	int src_index;
	src_index=search(src);
	cout<<"source is "<<array[src_index]->name<<endl;
	node* ptr=array[src_index]->next;
		while(ptr!=NULL){
 	  if((ptr->flight==flt)and(ptr->name==dst)){
 	  
 	cout<<"-destination-"<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
 	      temp1++;  
	   }

	   ptr=ptr->next; 
	 }
	 if(temp1==0){
	 	cout<<"sorry no flight found on specific destination :("<<endl;
	 	cout<<"below are available options "<<endl<<endl<<endl;
	 	path( src, dst);
	 }
	 
}





void display_direct_flights(){
	for(int i=0; i<10; i++){
 	cout<<"[Source]"<<endl;
 	cout<<"-"<<array[i]->name<<" :Hotel fair@day = "<<array[i]->hotelfair<<endl;
 	
 	cout<<"---Destination"<<endl;
 	node* ptr=array[i]->next;	
 	while(ptr!=NULL){
 	
 		cout<<"--"<<ptr->name<<" "<<ptr->date<<" "<<ptr->departure_time<<" "<<ptr->arrival_time<<" "<<ptr->cost<<" "<<ptr->flight<<endl;
 		ptr=ptr->next;
	 }
 	cout<<endl<<endl;
 }
 
}









int main()
{
char word[7][10];
	  string input;
    ifstream in;
    string lastinserted;
    string insert_input;
 in.open("Flights.txt",ios::in);
int scount;
 while(in){
 //	cout<<"open file"<<endl;
 	  int x1=0;
 	  int y1=0;
 		getline(in,input);
 		for(int i=0;input[i]!='\0';i++){
 			
 			if(input[i]==' '){
 				word[x1][y1]='\0';
 				y1=0;
 				x1++;
			 }
			 else{
			 	word[x1][y1]=input[i];
			 	y1++;
			 }
			 
		 }
		 word[x1][y1]='\0';
		 insert_input=word[0];
		//	 cout<<word[0]<<endl;
		source_insert(insert_input); 
		 
	//	cout<<word[1]<<endl;
 		
		 }
		 

        
in.close();
 
 
 
 
 
  in.open("Flights.txt",ios::in);
 while(in){
 //	cout<<"open file"<<endl;
 	  int x1=0;
 	  int y1=0;
 		getline(in,input);
 		for(int i=0;input[i]!='\0';i++){
 			
 			if(input[i]==' '){
 				word[x1][y1]='\0';
 				y1=0;
 				x1++;
			 }
			 else{
			 	word[x1][y1]=input[i];
			 	y1++;
			 }
			 
		 }
		 word[x1][y1]='\0';
		 insert_input=word[0];
		//	 cout<<word[0]<<endl;
		node* newnode=new node(word[1], word[2], word[3], word[4], word[5], word[6]);
		insert(search(insert_input), newnode); 
		 
	//	cout<<word[1]<<endl;
 		
		 }


   
        
in.close();
char word1[2][10];
  in.open("HotelCharges_perday.txt",ios::in);
 while(in){
 //	cout<<"open file"<<endl;
 	  int x1=0;
 	  int y1=0;
 		getline(in,input);
 		for(int i=0;input[i]!='\0';i++){
 			
 			if(input[i]==' '){
 				word1[x1][y1]='\0';
 				y1=0;
 				x1++;
			 }
			 else{
			 	word1[x1][y1]=input[i];
			 	y1++;
			 }
			 
		 }
		 word[x1][y1]='\0';
		 insert_input=word1[0];
		if(search(insert_input)!=-1)
		array[search(insert_input)]->hotelfair=word1[1]; 
		 
	//	cout<<word[1]<<endl;
 		
		 }
		 


   
        
in.close();
    cout<<"*************************************************"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"************FLIGHT RESERVATION SYSTEM************"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"*************************************************"<<endl; 
                
               //////////////////////////////////////////////////////////////////
              /////////////////    test samples for functions  /////////////////
              /////////////////////////////////////////////////////////////
                          /////////////////////////////////////

   char stop='9';
 while(stop!='0'){
 
     
  string source, destination,date ,flight;
     cout << "Enter source ";
     cin>>source;
    cout << "Enter destination ";
    cin>>destination;
 
 
 
 char ch;
 cout<<"\nchoose an option to perform operation :) "<<endl<<endl;
 cout<<"press '1' to check all avalibilities of flights \n"<<endl;
 cout<<"press '2' to check avalibility of flight on specific date  \n"<<endl;
 cout<<"press '3' check avalibility of desired airline flight  \n"<<endl;
 cout<<"press '4' to check minimum price for journey  \n"<<endl;
 cout<<"press '5' to check minimum time for journey  \n"<<endl;
 cin>>ch;
 

 switch (ch) {
  case '1':
   path(source, destination);
    break;
  case '2':
  	cout<<" enter date ";
  	cin>>date;
  date_path(source, destination,date);
    break;
  case '3':
  	cout<<" enter flight you want to travel ";
  	cin>>flight;
  	flight_path(source, destination,flight);
    break;
  case '4':
   minimum_price_path(source, destination);
    break;
    case '5':
    minimum_time_path(source, destination);
    break;
 
}

cout<<"press any key to continue or '0' to stop "<<endl;
cin>>stop;
}

 ///////////////////source to destination all possible paths ends;
 
}



