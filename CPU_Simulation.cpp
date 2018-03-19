#include<iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>
int M [10] = {2,4,7,8,9,1,3,6,5,0};
int mar=0;
int mbr1=0;
int pc=0;
int ac=0;
int n=0; 
using namespace std;

int INC()
{
	cout<<"\n\nINC -- INCREMENT ACCUMILATOR\n";
	ac=ac+1;
	cout<<"\nAC <-- AC + 1";
	cout<<"\nAC: ";
	cout<<ac;
	cout<<"\n";
	cout<<"___________________";
}


int CLA()
{
	cout<<"\n\nCLA -- CLEAR ACCUMILATOR";
	ac=0;
	cout<<"\nAC <-- 0";
	cout<<"\nAC: ";
	cout<<ac;
	cout<<"\n";
		cout<<"____________________";
}

int CMA()
{
	cout<<"\n\n CMA -- COMPLEMENT ACCUMILATOR";
	ac=-ac;
	cout<<"\n AC <-- AC'";
	cout<<"\nAC: ";
	cout<<ac;
	cout<<"\n";
		cout<<"___________________";
}

int SPA()
{
	cout<<"\n\nSPA -- SKIP ON POSSITIVE ACCUMILATOR";
	if(ac>0){
		pc=pc+1;
		cout<<"\n AC > 0, PC INCREMENTED";
		cout<<"\nPC: ";
		cout<<pc;
	}
	else
	cout<<"\n PC !> 0, PC NOT INCREMENTED";
	cout<<"\n";
		cout<<"____________________";
}

int SNA()
{
	cout<<"\n\nSNA -- SKIP ON NEGATIVE ACCUMILATOR";
	if(ac<0){
		pc=pc+1;
		cout<<"\n AC < 0, PC INCREMENTED";
		cout<<"\nPC: ";
		cout<<pc;
	}
	else
	cout<<"\n AC !< 0, PC NOT INCREMENTED";
		cout<<"_____________________";
}

int SZA()
{
	cout<<"\n\nSZA -- SKIP ON ZERO ACCUMILATOR";
	if(ac==0){
		pc=pc+1;
		cout<<"\n AC = 0, PC INCREMENTED";
		cout<<"\nPC: ";
		cout<<pc;
	}
	else
	cout<<"\n AC != 0, PC NOT INCREMENTED";
		cout<<"______________________";
}

int ISZ(string mbr)
{
	cout<<"\n\nISZ -- INCREMENT & SKIP IF 0\n";
	mar= mbr[4]-48;
	cout<<"MAR <-- MBR[Addr]\n";
    cout<<"MAR: ";
	cout<< mar;
	cout<<"\n";
	mbr1=M[mar];
	cout<<"MBR <-- M[MAR]\n";
	cout<<"MBR: ";
	cout<<mbr1;
	cout<<"\n";
	mbr1=mbr1+1;
	cout<<"MBR <-- MBR+1\n";
	cout<<"MBR: ";
	cout<<mbr1;
//	cout<<"\n";
	M[mar]=mbr1;
	cout<<"\nM[MAR] <-- MBR";
	cout<<"\nM[MAR]: ";
	cout<<M[mar];
	cout<<"\n";
	if(mbr1==0){
		pc=pc+1;
		cout<<"\nMBR = 0 & PC <-- PC+1";
		cout<<"\nPC: ";
		cout<<pc;
		cout<<"\n";
	}
	else
	cout<<"\n MBR != 0 & PC NOT INCREMENTED";
	cout<<"\n";
		cout<<"____________________";
}

int BSA(string mbr)
{
	cout<<"\n";
	cout<<"\n BSA -- BRANCH & SAVE ADDRESS\n";
	mar= mbr[4]-48;
	cout<<"MAR <-- MBR[Addr]\n";
    cout<<"MAR: ";
	cout<< mar;
	char temp= (char)(pc+48);
	//cout<<"\n temp: ";
	//cout<< temp;
	mbr= mbr.substr(0,4);
    string s;
    mbr+=temp;
    pc=mar;
    M[mar]=mar;
    pc=pc+1;
    cout<<"\nMBR[Addr] <-- PC";
    cout<<"\nMBR: ";
    cout<<mbr;
    cout<<"\nPC <-- MBR[Addr]";
    cout<<"\nPC: ";
    cout<<pc;
    cout<<"\nM[MAR] <-- MBR";
    cout<<"\nM[MAR]: ";
    cout<<M[mar];
    cout<<"\nPC <-- PC+1";
    cout<<"\nPC: ";
    cout<<pc;
    cout<<"\n";
    	cout<<"____________________";
}

int BUN(string mbr)
{
	cout<<"\n";
	cout<<"\nBUN -- BRANCH UNCONDITIONAL\n";
	int addr= mbr[4]-48;
	pc=addr;
	cout<<"PC <-- MBR\n";
	cout<<"PC: ";
	cout<<pc;
	cout<<"\n";
	n++;
		cout<<"_____________________";
}

int AND(string mbr)
{
	cout<<"\n";
	cout<<"\nAND -- AND TO ACCUMILATOR\n";
	mar= mbr[4]-48;
	cout<<"MAR <-- MBR[Addr]\n";
    cout<<"MAR: ";
	cout<< mar;
	cout<<"\n";
	mbr1=M[mar];
	cout<<"MBR <-- M[MAR]\n";
	cout<<"MBR: ";
	cout<<mbr1;
	cout<<"\n";
	ac= ac & mbr1;
	cout<<"AC <-- AC & MBR\n";
	cout<<"Content of AC: ";
	cout<<ac;
	cout<<"\n";
		cout<<"_____________________";
}

int STA(string mbr)
{
	cout<<"\n";
	cout<<"\nSTA -- STORE CONTENT OF AC TO RAM\n";
	mar= mbr[4]-48;
    cout<<"MAR <-- MBR[Addr]\n";
    cout<<"MAR: ";
	cout<< mar;
	cout<<"\n";
    mbr1=ac;
    cout<<"MBR <-- AC\n";
    cout<<"MBR: ";
	cout<<mbr1;
	cout<<"\n";
	M[mar]=ac;
	cout<<"M[MAR] <-- AC\n";
	cout<<"M[MAR]: ";
	cout<<M[mar];
	cout<<"\n";
		cout<<"____________________";
}

int ADD(string mbr)
{
	cout<<"\n";
	cout<<"\nADD--ADD To ACCUMILATOR\n";
	mar= mbr[4]-48;
	cout<<"MAR <-- MBR[Addr]\n";
	cout<<"MAR: ";
	cout<< mar;
	cout<<"\n";
	mbr1=M[mar];
	cout<<"MBR <-- M[MAR]\n";
	cout<<"MBR: ";
	cout<<mbr1;
	cout<<"\n";
	ac=ac+mbr1;
	cout<"AC <-- AC+MBR\n";
	cout<<"Content of AC:";
	cout<<ac;
	cout<<"\n";
		cout<<"______________________";
}

int LDA(string mbr)
{
	cout<<"\n";
	cout<<"\nLDA--LOAD ACCUMILATOR\n";
	cout<<"MAR <-- MBR[Addr]\n";
	cout<<"MAR: ";
	mar= mbr[4]-48;
	cout<< mar;
	cout<<"\n";
	mbr1=M[mar];
	cout<<"MBR <-- M[MAR] \n";
	cout<<"MBR: ";
	cout<<mbr1;
	cout<<"\n";
	ac=mbr1;
	cout<<"AC <-- MBR\n";
	cout<<"Content of AC: ";
	cout<<ac;
	cout<<"\n";
		cout<<"_____________________";
	
}

string fetch(vector <string> a)
{
	string opr;
	cout<<"   \n\nFETCH\n";
	mar=pc;
	cout<<"MAR <-- PC \n" ; 
	cout<<"MAR: ";
	cout<<mar;
	cout<<"\n";
    string mbr=a[mar];
	cout<<"MBR <-- M[MAR] \n" ;
	cout<<"MBR: " + mbr + "\n"; 
	string decide= mbr.substr(1,1);
	//cout<<"\n decide: "+decide;
	if(decide.compare("7")==0)
	opr=mbr.substr(1,4);
	else
	opr=mbr.substr(1,3);
	pc++; 
	cout<<"OPR <-- MBR[OPR] \n";
	cout<<"OPR: "+opr;
    
    
   
	string dir=mbr.substr(0,1);
	cout<<"\n dirrr:";
	cout<<dir;
	cout<<"\n";
	
	if(dir.compare("1")==0){
		cout<<"\n INDIRECT CYCLE";
		mar=mbr[4]-48;
		mar=M[mar];
		cout<<"\n MAR <-- MBR[Addr]";
		cout<<"\n MAR: ";
		cout<<mar;
		mar=mar+48;
		char newadd= (char)mar;
		mbr=mbr.substr(0,4);
		mbr=mbr+newadd;
	//	cout<<"\nchanged mbr";
	//	cout<<mbr;
	//	cout<<"\n\n";
		
		cout<<"\n MBR <-- M[MAR]";
		cout<<"\nNow MBR Has New Memory Form The Memory Location"; 
		cout<<"\nMBR: ";
		cout<<mbr;	
	}
	
	if(opr.compare("010")==0) {
	cout<<"\nInstruction: LDA";
	LDA(mbr);
    }
	else if(opr.compare("011")==0) {
	cout<<"\nInstruction: STA";
	STA(mbr);
    }
	else if(opr.compare("000")==0){
	cout<<"\nInstruction: AND";
	AND(mbr);
    }
	else if(opr.compare("001")==0) {
	cout<<"\nInstruction: ADD";
	ADD(mbr);
    }
	else if(opr.compare("100")==0) {
	cout<<"\nInstruction: BUN";
	BUN(mbr);
    }
	else if(opr.compare("101")==0) {
	cout<<"\nInstruction: BSA";
	BSA(mbr);
    }
	else if(opr.compare("110")==0) {
	cout<<"\nInstruction: ISZ";
	ISZ(mbr);
    }
    else if(opr.compare("7800")==0){
    	cout<<"\nInstruction: CLA";
    	CLA();
	}
	else if(opr.compare("7200")==0){
    	cout<<"\nInstruction: CMA";
    	CMA();
	}
	else if(opr.compare("7020")==0){
    	cout<<"\nInstruction: INC";
    	INC();
	}
	else if(opr.compare("7010")==0){
    	cout<<"\nInstruction: SPA";
    	SPA();
	}
	else if(opr.compare("7008")==0){
    	cout<<"\nInstruction: SNA";
    	SNA();
	}
	else if(opr.compare("7004")==0){
    	cout<<"\nInstruction: SZA";
    	SZA();
	}
	

	cout<<"\n";
	return mbr;
}

int main() {
   ifstream inFile;
   inFile.open("file.txt"); 
   string ab; 
   int q=0;
   int acreg1=0,acreg2=0,pcreg1=0,pcreg2=0;
   cout<<"\nInstructions at Memory Location 100:\n";
   
   vector< string > a(111); 
   if (inFile.is_open()) {
      while (!inFile.eof()) {
         inFile >> a[q];
         cout<<a[q]<<endl;
         q++;
      }
    }
    else cout<<"couldnt read file";
    inFile.close();
    cout<<"Number of Instructions: ";
    cout<<q;
    cout<<"\n\n";
    cout<<"\nInstrutions at Memory location 200:\n";
    ifstream inFile2;
    inFile2.open("file2.txt");
    int p=0;
    vector <string> b(111);
    if(inFile2.is_open()){
    	while(!inFile2.eof()){
    		inFile2>> b[p];
    		cout<<b[p]<<endl;
    		p++;
		}
	}
	 cout<<"Number of Instructions: ";
    cout<<p;
    //while(n<4)
  
    int rr=3;
    int rrcount1=0;
    int rrcount2=0;
    while((pcreg1<q) || (pcreg2<p)){
    	pc=pcreg1;
    	ac=acreg1;
    	while( (rrcount1<rr) && (pc<q)){
    		
    		fetch(a);
    		rrcount1++;
    		
		}
		pcreg1=pc;
    	acreg1=ac;
    	cout<<"\nPC and AC Values Backed Up";
		cout<<"\nSwitching To Memory Location 200";
		cout<<"\n_______________________________________________________________________________________";
		pc=pcreg2;
		ac=acreg2;
		while((rrcount2<rr) && (pc<p)){
			fetch(b);
			rrcount2++;
		}
		pcreg2=pc;
		acreg2=ac;
		
		rr=rr+3;
		//cout<<"\n pcreg1:";
		//cout<<pcreg1;
		//cout<<"\n pcreg2:";
		//cout<<pcreg2;
		cout<<"\nPC and AC Values Backed Up";
		cout<<"\nSwitching To Memory Location 100";
		cout<<"\n_______________________________________________________________________________________";
	}
    cout<<"\nPC content:";
    cout<<pc;
    return 0;  
}


