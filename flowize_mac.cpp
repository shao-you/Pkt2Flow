#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int main()
{
/*
2014-10-09 23:58:41.890115 00:24:8c:c7:27:eb 00:0e:38:fe:73:00, UDP (17), 
140.113.215.239.8414 222.161.96.181.12611: 25
*/
	ifstream input;
	ofstream output;
	input.open("filtered_file",ios::in);
	output.open("flow_file",ios::out);

	map< pair<string,string>, int > flow_mac;//src mac, dst mac
	map< pair<string,string>, int >::iterator it;

	char pattern[1000+1]="";
	if(!input.is_open())
	{
		cerr<<"error"<<endl;
		return 0;
	}

	int flow_count = 0;
	while(input.eof()==false)
	{
		input.getline(pattern,1000);//first
		char* tmp = strtok(pattern, ", ");
	if(!tmp) break;
		string date = tmp;
		tmp = strtok(NULL, ", ");
		string time = tmp;

		tmp = strtok(NULL, ", ");
		string src_mac = tmp;
		tmp = strtok(NULL, ", ");
		string dst_mac = tmp;

		pair<string,string> mac_pair = make_pair(src_mac,dst_mac);
		it = flow_mac.find(mac_pair);
		if(it == flow_mac.end())//not found
		{
			flow_mac.insert(pair< pair<string,string>,int >(mac_pair,flow_count));
			flow_count++;
			output<<src_mac<<" "<<dst_mac<<endl;
			//cout<<time<<endl;//simulate 1st pkt_in
		}
		else
		{
			//packet count++
			//accumulate packet bytes
		}
		input.getline(pattern,1000);//second
	}
	cout<<"Total # of flows: "<<flow_count<<endl;
	input.close();
	output.close();
}
