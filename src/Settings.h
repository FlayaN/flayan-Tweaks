#pragma once

class Settings : public clib_util::singleton::ISingleton<Settings>
{
public:
	class Fixes
	{
	public:
		void Load(CSimpleIniA& a_ini);

		// members
		bool frustumCheck{ true };
	};

	void Load();

	[[nodiscard]] const Fixes& GetFixes() const;

private:
	template <class T>
	static void get_value(CSimpleIniA& a_ini, T& a_value, const char* a_section, const char* a_key, const char* a_comment)
	{
		ini::get_value(a_ini, a_value, a_section, a_key, a_comment);

		if constexpr (std::is_same_v<bool, T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value);
		} else if constexpr (std::is_floating_point_v<T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value != 1.0);
		} else if constexpr (std::is_arithmetic_v<T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value != 0);
		}
	}

	// members
	Fixes fixes{};

	StringMap<bool> settingsMap{};
};
