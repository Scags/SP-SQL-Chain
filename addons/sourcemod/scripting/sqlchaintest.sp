#include <sourcemod>
#include <sqlchain>

#pragma semicolon 1
#pragma newdecls required

public void OnPluginStart()
{
	RegConsoleCmd("sm_test1", TEST1);
}

public Action TEST1(int client, int args)
{
	SQLChain chain = new SQLChain();
	chain.Select().From("bandatabase").Where("clientid").Is("1");
	char s[512]; chain.Reset(); chain.ReadString(s, 512);
	PrintToServer(s);
	delete chain;
	return Plugin_Handled;
}
