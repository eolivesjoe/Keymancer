#pragma once

#include "../remapper/Remapper.h"

#include <windows.h>
#include <atomic>

static remapper::Remapper* m_remapper;

namespace keyhook
{
	class KeyHook
	{
	public:
		KeyHook(remapper::Remapper& remapper);
		void run();

	private:
		static LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
		static input::Input keyboardVkToInput(DWORD vkCode, WPARAM wCaram);

		static LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam);
		static input::Input mouseWParamToInput(WPARAM wParam);

	private:
		static remapper::Remapper* m_remapper;
		static std::atomic<bool> m_keymancerEnabled;
		static std::atomic<bool> m_running;
	};
} // namespace keyhook