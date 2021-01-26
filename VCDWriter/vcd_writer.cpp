// Class that helps to write to VCD file.
// This can be used to create timeline diagrams.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

enum varType{
    VAR_TYPE_SCALAR,            // 4 states 0,1,X,Z
    //VAR_TYPE_VECTOR_BINARY,   // Multiple bit value but in 0s and 1s
    //VAR_TYPE_VECTOR_REAL,
    //VAR_TYPE_STRING
};

// Class that can be used as VCD Writer, Refer to main() for example
//For help _Check
//https://web.archive.org/web/20120323132708/http://www.beyondttl.com/vcd.php

class VCDWriter {

private:
    ofstream vcdOut;
    vector <char> identifiers {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '~', '`', '+', '[', ']', '{', '}', '|', '<', '>', '?',
                               'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
    vector <char> idInUse;

    void add_date()
    {
        time_t now = time(0);
        vcdOut<<"$date "<<ctime(&now)<<" $end"<<endl;
    }

public:

    /////////// Functions that help to define the VCD file ////////////
    void add_comment(string comment)
    {
        vcdOut<<"$comment "<<comment<<" $end"<<endl;
    }
    void add_scope(string moduleName)
    {
        vcdOut<<"$scope module "<<moduleName<<" $end"<<endl;
    }
    void add_upscope()
    {
        vcdOut<<"$upscope $end"<<endl;
    }

    /*
    VCD Syntax:
		$var var_type size identifier reference $end
		var_type =  event | integer | parameter | real | reg | 
                            supply0 | supply1 | time | tri | triand | 
                            trior | trireg | tri0 | tri1 | wand | wire | wor
		size = decimal value of number of bits.
		refName = bit or vector name mapped to the identifier
	Examples:
		$var wire 1 * en_q $end
		$var reg 8 ( data_q[7:0] $end
    */
    char add_var(string var_type, string size, string refname)
    {
        char id;
        //Choose identifier
        if(identifiers.size() != 0)
        {
            id = identifiers[identifiers.size()-1];
            identifiers.pop_back();
            idInUse.push_back(id);
        }
        else
        {
            cout<<"ERROR: Exhausted identifiers !";
            exit(-1);
        }
        
        vcdOut<<"$var "<<var_type<<" "<<size<<" "<<id<<" "<<refname<<" $end"<<endl;
        return id;
    }

    void add_enddefinitions()
    {
        vcdOut<<"$enddefinitions $end"<<endl;

        // Initialize all wires to zero
        vcdOut<<"#0"<<endl;
        vector<char>::iterator idIterator;
        for(idIterator = idInUse.begin(); idIterator != idInUse.end(); idIterator++ )
        {
            vcdOut<<"0"<<*idIterator<<endl;
        }
    }

    /////////// Functions that help to record Value changes ////////////////
    void add_valueChange(varType type, char id, string timestamp, string value)
    {
        if(type == VAR_TYPE_SCALAR)
        {
            vcdOut<<"#"<<timestamp<<endl;
            vcdOut<<value<<id<<endl;
        }
        /*else
        {
            if(type == VAR_TYPE_VECTOR_BINARY)
            {
                vcdOut<<"b"<<value<<" "<<endl;
            }
            else
            {
                vcdOut<<"r"<<value<<" "<<endl;                
            }            
        }*/
    }

    void add_activity(varType type, char id, int timestamp, int duration)
    {
        add_valueChange(type, id, to_string(timestamp), "1");
        add_valueChange(type, id, to_string(timestamp+duration), "0");
    }

    //Input parameters:
    //VCD output file name, Time scale
    //Adds date by default

    //Possible values for Timeunit
    //s | ms | us | ns | ps | fs
    VCDWriter(string vcdFile, int timenum, string timeunit)
    {
        vcdOut.open(vcdFile);

        vcdOut<<"$timescale "<<timenum<<" "<<timeunit<<" $end"<<endl;
        add_date();

        vcdOut.flush();
    }

    ~VCDWriter()
    {
        vcdOut.flush();
        vcdOut.close();
    }
};


int main()
{
    VCDWriter *vcdwriter = new VCDWriter("C:/Rakesh/Code/Github/Tools/VCD/test.vcd", 1, "us");
    vcdwriter->add_comment("Random read 4K 100%");
    
    vcdwriter->add_scope("top");

    vcdwriter->add_scope("Host");
        char sLat = vcdwriter->add_var("wire", "1", "SLat");
        // Add wire for each tag ID?
    vcdwriter->add_upscope();
    
    vcdwriter->add_scope("HCore");
        char hCoreFW =  vcdwriter->add_var("wire", "1", "HCoreFW");
    vcdwriter->add_upscope();

    vcdwriter->add_scope("FCore");
        char fCoreFW =  vcdwriter->add_var("wire", "1", "FCoreFW");
    vcdwriter->add_upscope();

    vcdwriter->add_scope("Controller");
        char hDMA =  vcdwriter->add_var("wire", "1", "HDMA");
        vcdwriter->add_scope("CH0");
            char fDMACH0 =  vcdwriter->add_var("wire", "1", "FDMACH0");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH1");
            char fDMACH1 =  vcdwriter->add_var("wire", "1", "FDMACH1");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH2");
            char fDMACH2 =  vcdwriter->add_var("wire", "1", "FDMACH2");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH3");
            char fDMACH3 =  vcdwriter->add_var("wire", "1", "FDMACH3");
        vcdwriter->add_upscope();
    vcdwriter->add_upscope();

    vcdwriter->add_scope("NAND");
        vcdwriter->add_scope("CH0Bank0");
            char programTLCCH0Bank0 =  vcdwriter->add_var("wire", "1", "programcharTLCCH0Bank0");
            char programSLCCH0Bank0 =  vcdwriter->add_var("wire", "1", "programcharSLCCH0Bank0");
            char readCH0Bank0 =  vcdwriter->add_var("wire", "1", "readCH0Bank0");
            char eraseCH0Bank0 =  vcdwriter->add_var("wire", "1", "eraseCH0Bank0");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH1Bank0");
            char programTLCCH1Bank0 =  vcdwriter->add_var("wire", "1", "programcharTLCCH1Bank0");
            char programSLCCH1Bank0 =  vcdwriter->add_var("wire", "1", "programcharSLCCH1Bank0");
            char readCH1Bank0 =  vcdwriter->add_var("wire", "1", "readCH1Bank0");
            char eraseCH1Bank0 =  vcdwriter->add_var("wire", "1", "eraseCH1Bank0");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH2Bank0");
            char programTLCCH2Bank0 =  vcdwriter->add_var("wire", "1", "programcharTLCCH2Bank0");
            char programSLCCH2Bank0 =  vcdwriter->add_var("wire", "1", "programcharSLCCH2Bank0");
            char readCH2Bank0 =  vcdwriter->add_var("wire", "1", "readCH2Bank0");
            char eraseCH2Bank0 =  vcdwriter->add_var("wire", "1", "eraseCH2Bank0");
        vcdwriter->add_upscope();
        vcdwriter->add_scope("CH3Bank0");
            char programTLCCH3Bank0 =  vcdwriter->add_var("wire", "1", "programcharTLCCH3Bank0");
            char programSLCCH3Bank0 =  vcdwriter->add_var("wire", "1", "programcharSLCCH3Bank0");
            char readCH3Bank0 =  vcdwriter->add_var("wire", "1", "readCH3Bank0");
            char eraseCH3Bank0 =  vcdwriter->add_var("wire", "1", "eraseCH3Bank0");
        vcdwriter->add_upscope();
    vcdwriter->add_upscope();

    vcdwriter->add_upscope();
    vcdwriter->add_enddefinitions();

    // QD4
    vcdwriter->add_activity(VAR_TYPE_SCALAR, sLat, 10, 2);
    
    vcdwriter->add_activity(VAR_TYPE_SCALAR, sLat, 12, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hCoreFW, 12, 2);
    
    vcdwriter->add_activity(VAR_TYPE_SCALAR, sLat, 14, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hCoreFW, 14, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fCoreFW, 12, 4);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, sLat, 16, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hCoreFW, 16, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fCoreFW, 16, 4);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, hCoreFW, 18, 2);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fCoreFW, 20, 4);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, fCoreFW, 24, 4);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, readCH0Bank0, 16, 50);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fDMACH0, 66, 8);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hDMA, 74, 10);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, readCH1Bank0, 20, 50);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fDMACH1, 70, 8);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hDMA, 84, 10);
    
    vcdwriter->add_activity(VAR_TYPE_SCALAR, readCH2Bank0, 24, 50);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fDMACH2, 74, 8);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hDMA, 94, 10);

    vcdwriter->add_activity(VAR_TYPE_SCALAR, readCH3Bank0, 28, 50);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, fDMACH3, 78, 8);
    vcdwriter->add_activity(VAR_TYPE_SCALAR, hDMA, 104, 10);
  
    /*

    while
        numcmd = 50

        subqueue

        h2fqueue
        ch0b0queue
        ch0dmaqueue

        hostdmaqueue

    */

    delete vcdwriter;
    return 0;
}


/*
string event = "event";
string integer = "integer";
string parameter = "parameter";
string real = "real";
string realtime = "realtime";
string reg = "reg";
string supply0 = "supply0";
string supply1 = "supply1";
string timetype = "time";
string tri = "tri";
string triand = "triand";
string trior = "trior";
string trireg = "trireg";
string tri0 = "tri0";
string tri1 = "tri1";
string wand = "wand";
string wire = "wire";
string wor = "wor";
string stringtype = "string";   // Only supported by GTK Wave
*/