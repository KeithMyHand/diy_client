#include "Local.h"

CCDictionary* Local::dictionary = nullptr;

void Local::onInitDictionary(const char* string)
{
	dictionary = CCDictionary::createWithContentsOfFileThreadSafe(string);
}

const char* Local::L(const char* string)
{
	if (string == nullptr || string == "")
		return nullptr;
	return ((CCString*)dictionary->objectForKey(string))->getCString();
}