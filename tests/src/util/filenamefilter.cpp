/*
 * Copyright 2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "filenamefilter.h"

using namespace log4cxx;
using namespace log4cxx::helpers;

FilenameFilter::FilenameFilter(const char* actual, const char* expected)
    : pattern(" "),
      replacement(" ") {
    pattern += actual;
	size_t backslash = pattern.rfind('\\', pattern.length() - 1);
	while (backslash != std::string::npos) {
		pattern.replace(backslash, 1, "\\\\", 2);
		if (backslash == 0) {
			backslash = std::string::npos;
		} else {
		    backslash = pattern.rfind('\\', backslash - 1);
		}
	}


    replacement += expected;
}

String FilenameFilter::filter(const String& in)
	const throw(UnexpectedFormatException)
{
	return merge(pattern, in, replacement);
}


