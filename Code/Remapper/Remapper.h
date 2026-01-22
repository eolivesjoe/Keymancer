#pragma once

#include "../input/Input.h"
#include "../input/InputHash.h"

#include <unordered_map>
#include <string>

namespace remapper
{
	class Remapper
	{
	public:
		Remapper(const std::string& configPath);
		bool load();
		bool hasMapping(const input::Input& input) const;
		input::Input getMappedKey(const input::Input& input) const;

	private:
		bool isValidMappingLine(const std::string& line); 
		void processMappingLine(const std::string& line);
		input::Input parseInput(const std::string& s, input::State state);

	private:
		std::string m_configName;
		std::unordered_map<input::Input, input::Input> m_remaps;
	};
} // namespace remapper