#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <Poco/DirectoryIterator.h>
#include <Poco/File.h>
#include <Poco/Path.h>

static bool CompareLastModified(const Poco::File& f1, const Poco::File& f2)
{
    return f1.getLastModified().raw() < f2.getLastModified().raw();
}

static void DeleteOldLogs(const std::string& directory, const std::string& subString, const unsigned long long maxBytes = 1024 * 1024 * 1024)
{
    using std::vector;
    using Poco::DirectoryIterator;
    using Poco::File;
    using Poco::Path;

    //check directory
    if (!File(Path::expand(directory)).exists())
    {
        return;
    }

    //count
    unsigned long long totalBytes = 0;
    vector<File> files;
    DirectoryIterator it(File(Path::expand(directory)));
    DirectoryIterator end;
    while (it != end)
    {
        if (std::string::npos != it.name().find(subString))
        {
            files.push_back(*it);
            totalBytes += it->getSize();
        }
        ++it;
    }
    //sort
    sort(files.begin(), files.end(), CompareLastModified);
    //delete
    for (auto file = files.begin(); file != files.end() && totalBytes > maxBytes; ++file)
    {
        totalBytes -= file->getSize();
        file->remove();
    }
}
