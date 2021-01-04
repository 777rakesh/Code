// Simple C Class that helps to output VCD data.
// This can be used to create timeline diagrams.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Simple class that can be used as VCD Writer, Refer to main() for example
class VCDWriter {

//For help _Check
//https://web.archive.org/web/20120323132708/http://www.beyondttl.com/vcd.php

private:
    ofstream vcdOut;

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
    void unscope()
    {
        vcdOut<<"$unscope $end"<<endl;
    }

    void add_date()
    {
        time_t now = time(0);
        vcdOut<<"$date "<<ctime(&now)<<" $end"<<endl;
    }

    /*
    VCD Syntax:
		$var var_type size identifier reference $end
		var_type =  event | integer | parameter | real | reg | 
                            supply0 | supply1 | time | tri | triand | 
                            trior | trireg | tri0 | tri1 | wand | wire | wor
		size = decimal value of number of bits.
		identifier = name of the variable in printable ASCII characters.
		reference = bit or vector name mapped to the identifier
	Examples:
		$var wire 1 * en_q $end
		$var reg 8 ( data_q[7:0] $end
    */
    void add_var(string var_type, string size, string refname)
    {
        //Generate identifier
        string identifier;

        //Save refname to identifier mapping

        //TODO add identifier
        vcdOut<<"$var "<<var_type<<" "<<size<<" "<<"$"<<" "<<refname<<" $end"<<endl;
    }

    void enddefinitions()
    {
        vcdOut<<"$enddefinitions $end"<<endl;
    }

    /////////// Functions that help to record Value changes ////////////////
    void value_change()
    {

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
    VCDWriter *vcdwriter = new VCDWriter("D:/Rakesh/Github/Tools/VCD/test.vcd", 1, "us");
 
    vcdwriter->add_comment("Random read 4K 100%");
    vcdwriter->add_scope("host");
    vcdwriter->add_var("integer", "1", "tag");
    vcdwriter->unscope();
    vcdwriter->enddefinitions();

    delete vcdwriter;
    return 0;
}

#if 0
    /// Writes a `#xxx` timestamp.
    pub fn timestamp(&mut self, ts: u64) -> io::Result<()> {
        writeln!(self.writer, "#{}", ts)
    }

    /// Writes a change to a scalar variable.
    pub fn change_scalar<V: Into<Value>>(&mut self, id: IdCode, v: V) -> io::Result<()> {
        writeln!(self.writer, "{}{}", v.into(), id)
    }

    /// Writes a change to a vector variable.
    pub fn change_vector(&mut self, id: IdCode, v: &[Value]) -> io::Result<()> {
        write!(self.writer, "b")?;
        for i in v {
            write!(self.writer, "{}", i)?
        }
        writeln!(self.writer, " {}", id)
    }

    /// Writes a change to a real variable.
    pub fn change_real(&mut self, id: IdCode, v: f64) -> io::Result<()> {
        writeln!(self.writer, "r{} {}", v, id)
    }

    /// Writes a change to a string variable.
    pub fn change_string(&mut self, id: IdCode, v: &str) -> io::Result<()> {
        writeln!(self.writer, "s{} {}", v, id)
    }

#endif