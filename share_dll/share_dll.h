#pragma once
#include "../share_lib/share_formside.h"

using namespace System;

namespace sharedll {
	public ref class ShareMemoryCSharp
	{
	public:
		ShareMemoryCSharp();
		~ShareMemoryCSharp();
		!ShareMemoryCSharp();

	private:
		SHARE_MEM_FORM_SIDE *shareMemory_;

	public:
		bool IsShareMemoryReady(){
			if (!shareMemory_)
				return false;
			if (!shareMemory_->ShareMemoryDataPtr)
				return false;
			if (!shareMemory_->ShareMemoryDataPtr->systemRunning)
				return false;
			return true;
		}
		void EnableCount() {
			if (shareMemory_ && shareMemory_->ShareMemoryDataPtr)
				shareMemory_->ShareMemoryDataPtr->Enable = true;
		}
		void DisableCount() {
			if (shareMemory_ && shareMemory_->ShareMemoryDataPtr)
				shareMemory_->ShareMemoryDataPtr->Enable = false;
		}
		bool IsCountEnabled() {
			if (shareMemory_ && shareMemory_->ShareMemoryDataPtr)
				return shareMemory_->ShareMemoryDataPtr->Enable;
			return false;
		}
	};
}
