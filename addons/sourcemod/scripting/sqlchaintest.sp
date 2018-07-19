#include <sourcemod>
#include <sqlchain>

#define PROFILER
#if defined PROFILER
#include <profiler>
#endif

#pragma semicolon 1
#pragma newdecls required

public void OnPluginStart()
{
	RegConsoleCmd("sm_test1", TEST1);
}

public Action TEST1(int client, int args)
{
#if defined PROFILER
	Handle p = CreateProfiler();
	StartProfiling(p);
#endif
	SQLChain chain = new SQLChain();
	chain.Select("*")
		.From("%s", "bandatabase")
		.Where("clientid = %d", args);
	char s[512]; chain.Reset(); chain.ReadString(s, 512);
	PrintToServer(s);

	chain.Clear();

	char id[22] = "STEAM_0:0:62618404";
	char name[22] = "Scag";
	char ip[22] = "0.0.0.0";
	int time = 10080;

	chain.Insert()
		.Into("%s (steamid, name, ip_address, ban_time)", "bandatabase")
		.Values("(%s, %s, %s, %d)", id, name, ip, time);

	chain.Reset(); chain.ReadString(s, 512);
	PrintToServer(s);

#if defined PROFILER
	StopProfiling(p);
	PrintToServer("%0.10f", GetProfilerTime(p));
	delete p;
#endif
	delete chain;
	return Plugin_Handled;
}
