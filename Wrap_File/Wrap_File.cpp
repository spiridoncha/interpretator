#include "Wrap_File.h"
Wrap_File::Wrap_File(const Wrap_File &other)
{
	ref = other.ref;
	file = other.file;
	ref->AddRef();
}

Wrap_File& Wrap_File::operator=(const Wrap_File &other)
{
	if (this != &other)
	{
		if (ref->DelRef() == 0)
		{
			delete ref;
			fclose(file);
		}
		ref = other.ref;
		file = other.file;
		ref->AddRef();
	}
	return *this;
}

Wrap_File& Wrap_File::operator=(Wrap_File &&other)
{
	if (ref->DelRef() == 0)
	{
		delete ref;
		fclose(file);
	}
	ref = other.ref;
	file = other.file;
	other.file = nullptr;
	other.ref = nullptr;
	return *this;
}
