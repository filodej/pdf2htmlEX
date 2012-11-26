#include "TmpFiles.h"
#include "Param.h"
#include <iostream>

using namespace std;

namespace pdf2htmlEX {


TmpFiles::TmpFiles( Param const& param_ )
	: param( param_ )
{
}

TmpFiles::~TmpFiles()
{ 
    clean();
}

void TmpFiles::add(const string & fn)
{
    if(!param.clean_tmp)
        return;

    if(tmp_files.insert(fn).second && param.debug)
        cerr << "Add new temporary file: " << fn << endl;
}

void TmpFiles::clean()
{
    if(!param.clean_tmp)
        return;

    for(auto iter = tmp_files.begin(); iter != tmp_files.end(); ++iter)
    {
        const string & fn = *iter;
        remove(fn.c_str());
        if(param.debug)
            cerr << "Remove temporary file: " << fn << endl;
    }

    remove(param.tmp_dir.c_str());
    if(param.debug)
        cerr << "Remove temporary directory: " << param.tmp_dir << endl;
}


} // namespace pdf2htmlEX