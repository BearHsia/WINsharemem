#include "pch.h"

#include "share_dll.h"

namespace sharedll {
	ShareMemoryCSharp::ShareMemoryCSharp() {
		shareMemory_ = new SHARE_MEM_FORM_SIDE();
	}
	ShareMemoryCSharp::~ShareMemoryCSharp() {
		this->!ShareMemoryCSharp();
	}
	ShareMemoryCSharp::!ShareMemoryCSharp() {
		if (shareMemory_ != nullptr)
			delete shareMemory_;
	}
}