#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Data::Xml::Dom;

int main()
{
    init_apartment();

    StorageFile file = StorageFile::GetFileFromPathAsync(L"C:\\Users\\gaeta\\Works\\ReadXMLWinRT\\XMLFile.xml").get();

    XmlLoadSettings settings = XmlLoadSettings();
    settings.ElementContentWhiteSpace(false);

	XmlDocument doc = XmlDocument::LoadFromFileAsync(file, settings).get();

    XmlElement root = doc.DocumentElement();
    XmlNodeList childNodes = root.ChildNodes();

    printf("There are %d elements\n", childNodes.Size());
	printf("====\n");
    for (IXmlNode child : childNodes)
    {
        auto childs = child.ChildNodes();
        if (childs.Size() > 0)
        {
            printf("Name: %ls\n", childs.Item(0).InnerText().c_str());
            printf("Job: %ls\n", childs.Item(1).InnerText().c_str());
        }
        else
            printf("INVALID\n");
    	
        printf("====\n");
    }

    return 0;
}
