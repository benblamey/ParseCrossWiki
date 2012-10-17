// ParseCrossWiki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// reading a text file
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	vector<string> words;
	// Rhi top 35 TF/IDF scoring words:
	//words.push_back("avaaz");
	//words.push_back("awsc2012");
	//words.push_back("barnhall");
	//words.push_back("cermony");
	//words.push_back("clemency");
	//words.push_back("coercion");
	//words.push_back("diarrhoel");
	//words.push_back("framework");
	//words.push_back("friends »");
	//words.push_back("garczynska");
	//words.push_back("geogro");
	//words.push_back("gregynog");
	//words.push_back("gretting");
	//words.push_back("guadalquivir");
	//words.push_back("guaridan");
	//words.push_back("homeoffice");
	//words.push_back("homeofficesurveys");
	//words.push_back("kwiksurveys");
	//words.push_back("llywodraeth");
	////words.push_back("ound");
	//words.push_back("pardons");
	//words.push_back("purchasians");
	//words.push_back("questionnaire");
	//words.push_back("raggie");
	//words.push_back("sanitation");
	//words.push_back("witdrawn");
	//words.push_back("baselayer");
	//words.push_back("snp");
	//words.push_back("aiuk");
	//words.push_back("scrabulous");
	//words.push_back("lmbc");
	//words.push_back("rugbystore");
	//words.push_back("superstore");
	//words.push_back("wateraid200");
	//words.push_back("wateraid");

	// Luke top 35 TFIDF scoring words.
	words.push_back("tacoma");
	words.push_back("tartine");
	words.push_back("valuation");
	words.push_back("webpages");
	words.push_back("wichcraft");
	words.push_back("yeates");
	words.push_back("foursquare");
	words.push_back("seo");
	words.push_back("trafficking");
	words.push_back("@quora");
	words.push_back("carmarthen");
	words.push_back("damson");
	words.push_back("kony");
	words.push_back("memolane");
	words.push_back("musings");
	words.push_back("petitions");
	words.push_back("pinterest");
	words.push_back("questionnaire");
	words.push_back("senadee");
	words.push_back("274");
	words.push_back("scrabulous");
	words.push_back("3zframes");
	words.push_back("bt5");
	words.push_back("bulaquo");
	words.push_back("cisor");
	words.push_back("manavo");
	words.push_back("milesaway");
	words.push_back("«");
	words.push_back("aikman");
	words.push_back("freight");
	words.push_back("moldavia");
	words.push_back("quora");
	words.push_back("shares");
	words.push_back("holdem");
	words.push_back("loccit");

	string line;
	ifstream myfile ("D:\\corpora\\crosswiki\\dictionary");
	if (myfile.is_open())
	{
		int i = 0;
		while ( myfile.good() )
		{
			i++;
			if (i % 100000 == 0) 
			{ 
				cerr << i;
				cerr << "...";
			}
			getline (myfile,line);
			size_t tabPos = line.find("\t");
			if (tabPos == 1) continue;
			transform(line.begin(), line.end(), line.begin(), ::tolower);

			for(std::vector<string>::iterator it = words.begin(); it != words.end(); ++it) 
			{
				if ((*it).length() != tabPos) continue;
				if (0==line.substr(0,(*it).length()).compare(*it)) 
					//if (0 == line.compare(0,tabPos-1,*it, 0, tabPos-1))
					//if (string::npos != line.substr(0,tabPos-1).find(*it))
					//if (0 == (*it).compare(line.substr(0,(*it).length())))
				{
					cout << *it;
					cout << "\t";
					cout << line;
					cout << "\r\n";
					break;
				}
			}


		}
		myfile.close();
	}

	else cout << "Unable to open file"; 

	//std::cout << "Press ENTER to continue... " << flush;
	// std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );

	return 0;
}

