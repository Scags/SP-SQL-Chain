#if defined _sqlchain_included
  #endinput
#endif
#define _sqlchain_included

stock static char g_strSQLChain[2][4096]; 	// Disgusting

methodmap SQLChain < DataPack
{
	public SQLChain()
	{
		DataPack pack = new DataPack();
		pack.WriteString("");
		return view_as< SQLChain >(pack);
	}

	public SQLChain Do( char[] keywordstr )	// Private tags please ;-;
	{
		this.Reset();
		this.ReadString(g_strSQLChain[0], sizeof(g_strSQLChain[]));
		Format(g_strSQLChain[0], sizeof(g_strSQLChain[]), "%s %s %s", g_strSQLChain[0], keywordstr, g_strSQLChain[1]);
		this.Reset(true);
		this.WriteString(g_strSQLChain[0]);
		return this;
	}

	public void Query( Database db, SQLQueryCallback callback, any data = 0, DBPriority prio = DBPrio_Normal )
	{
		this.Reset();
		this.ReadString(g_strSQLChain[0], sizeof(g_strSQLChain[]));
		db.Query(callback, g_strSQLChain[0], data, prio);
	}

	public void Clear()
	{
		this.Reset(true);
		this.WriteString("");
	}

	public SQLChain Clone()
	{
		SQLChain chain = new SQLChain();
		this.Reset();
		this.ReadString(g_strSQLChain[0], sizeof(g_strSQLChain[]));
		chain.WriteString(g_strSQLChain[0]);
		return chain;
	}

	public SQLChain Add( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ADD");
	}

	public SQLChain External( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXTERNAL");
	}

	public SQLChain All( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ALL");
	}

	public SQLChain Fetch( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FETCH");
	}

	public SQLChain Alter( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ALTER");
	}

	public SQLChain File( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FILE");
	}

	public SQLChain And( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("AND");
	}

	public SQLChain FillFactor( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FILLFACTOR");
	}

	public SQLChain Any( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ANY");
	}

	public SQLChain For( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FOR");
	}

	public SQLChain As( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("AS");
	}

	public SQLChain Foreign( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FOREIGN");
	}

	public SQLChain Asc( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ASC");
	}

	public SQLChain FreeText( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FREETEXT");
	}

	public SQLChain Authorization( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("AUTHORIZATION");
	}

	public SQLChain FreeTextTable( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FREETEXTTABLE");
	}

	public SQLChain Backup( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BACKUP");
	}

	public SQLChain From( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FROM");
	}

	public SQLChain Begin( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BEGIN");
	}

	public SQLChain Full( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FULL");
	}

	public SQLChain Between( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BETWEEN");
	}

	public SQLChain Function( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("FUNCTION");
	}

	public SQLChain Break( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BREAK");
	}

	public SQLChain Goto( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("GOTO");
	}

	public SQLChain Browse( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BROWSE");
	}

	public SQLChain Grant( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("GRANT");
	}

	public SQLChain Bulk( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BULK");
	}

	public SQLChain Group( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("GROUP");
	}

	public SQLChain By( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("BY");
	}

	public SQLChain Having( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("HAVING");
	}

	public SQLChain Cascade( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CASCADE");
	}

	public SQLChain HoldLock( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("HOLDLOCK");
	}

	public SQLChain Case( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CASE");
	}

	public SQLChain Identity( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IDENTITY");
	}

	public SQLChain Check( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CHECK");
	}

	public SQLChain IDentity_Insert( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IDENTITY_INSERT");
	}

	public SQLChain Checkpoint( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CHECKPOINT");
	}

	public SQLChain IdentityCol( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IDENTITYCOL");
	}

	public SQLChain Close( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CLOSE");
	}

	public SQLChain If( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IF");
	}

	public SQLChain Clustered( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CLUSTERED");
	}

	public SQLChain In( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IN");
	}

	public SQLChain Coalesce( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("COALESCE");
	}

	public SQLChain Index( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("INDEX");
	}

	public SQLChain Collate( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("COLLATE");
	}

	public SQLChain Inner( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("INNER");
	}

	public SQLChain Column( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("COLUMN");
	}

	public SQLChain Insert( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("INSERT");
	}

	public SQLChain Commit( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("COMMIT");
	}

	public SQLChain Intersect( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("INTERSECT");
	}

	public SQLChain Compute( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("COMPUTE");
	}

	public SQLChain Into( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("INTO");
	}

	public SQLChain Constraint( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CONSTRAINT");
	}

	public SQLChain Is( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("IS");
	}

	public SQLChain Contains( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CONTAINS");
	}

	public SQLChain Join( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("JOIN");
	}

	public SQLChain ContainsTable( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CONTAINSTABLE");
	}

	public SQLChain Key( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("KEY");
	}

	public SQLChain Continue( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CONTINUE");
	}

	public SQLChain Kill( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("KILL");
	}

	public SQLChain Convert( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CONVERT");
	}

	public SQLChain Left( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("LEFT");
	}

	public SQLChain Create( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CREATE");
	}

	public SQLChain Like( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("LIKE");
	}

	public SQLChain Cross( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CROSS");
	}

	public SQLChain Lineno( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("LINENO");
	}

	public SQLChain Current( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURRENT");
	}

	public SQLChain Load( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("LOAD");
	}

	public SQLChain Current_Date( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURRENT_DATE");
	}

	public SQLChain Merge( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("MERGE");
	}

	public SQLChain Current_Time( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURRENT_TIME");
	}

	public SQLChain National( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NATIONAL");
	}

	public SQLChain Current_Timestamp( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURRENT_TIMESTAMP");
	}

	public SQLChain NoCheck( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NOCHECK");
	}

	public SQLChain Current_User( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURRENT_USER");
	}

	public SQLChain NonClustered( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NONCLUSTERED");
	}

	public SQLChain Cursor( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("CURSOR");
	}

	public SQLChain Not( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NOT");
	}

	public SQLChain Database( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DATABASE");
	}

	public SQLChain Null( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NULL");
	}

	public SQLChain Dbcc( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DBCC");
	}

	public SQLChain NullIf( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("NULLIF");
	}

	public SQLChain Deallocate( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DEALLOCATE");
	}

	public SQLChain Of( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OF");
	}

	public SQLChain Declare( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DECLARE");
	}

	public SQLChain Off( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OFF");
	}

	public SQLChain Default( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DEFAULT");
	}

	public SQLChain Offsets( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OFFSETS");
	}

	public SQLChain Delete( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DELETE");
	}

	public SQLChain On( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ON");
	}

	public SQLChain Deny( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DENY");
	}

	public SQLChain Open( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPEN");
	}

	public SQLChain Desc( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DESC");
	}

	public SQLChain OpenDataSource( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPENDATASOURCE");
	}

	public SQLChain Disk( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DISK");
	}

	public SQLChain OpenQuery( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPENQUERY");
	}

	public SQLChain Distinct( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DISTINCT");
	}

	public SQLChain Openrowset( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPENROWSET");
	}

	public SQLChain Distributed( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DISTRIBUTED");
	}

	public SQLChain Openxml( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPENXML");
	}

	public SQLChain Double( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DOUBLE");
	}

	public SQLChain Option( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OPTION");
	}

	public SQLChain Drop( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DROP");
	}

	public SQLChain Or( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OR");
	}

	public SQLChain Dump( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("DUMP");
	}

	public SQLChain Order( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ORDER");
	}

	public SQLChain Else( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ELSE");
	}

	public SQLChain Outer( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OUTER");
	}

	public SQLChain End( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("END");
	}

	public SQLChain Over( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("OVER");
	}

	public SQLChain Errlvl( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ERRLVL");
	}

	public SQLChain Percent( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PERCENT");
	}

	public SQLChain Escape( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ESCAPE");
	}

	public SQLChain Pivot( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PIVOT");
	}

	public SQLChain Except( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXCEPT");
	}

	public SQLChain Plan( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PLAN");
	}

	public SQLChain Exec( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXEC");
	}

	public SQLChain Precision( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PRECISION");
	}

	public SQLChain Execute( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXECUTE");
	}

	public SQLChain Primary( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PRIMARY");
	}

	public SQLChain Exists( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXISTS");
	}

	public SQLChain Print( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PRINT");
	}

	public SQLChain Exit( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("EXIT");
	}

	public SQLChain Proc( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PROC");
	}

	public SQLChain Procedure( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PROCEDURE");
	}

	public SQLChain Public( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("PUBLIC");
	}

	public SQLChain Raiserror( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RAISERROR");
	}

	public SQLChain Read( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("READ");
	}

	public SQLChain ReadText( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("READTEXT");
	}

	public SQLChain Reconfigure( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RECONFIGURE");
	}

	public SQLChain References( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("REFERENCES");
	}

	public SQLChain Replication( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("REPLICATION");
	}

	public SQLChain Restore( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RESTORE");
	}

	public SQLChain Restrict( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RESTRICT");
	}

	public SQLChain Return( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RETURN");
	}

	public SQLChain Revert( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("REVERT");
	}

	public SQLChain Revoke( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("REVOKE");
	}

	public SQLChain Right( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RIGHT");
	}

	public SQLChain Rollback( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ROLLBACK");
	}

	public SQLChain RowCount( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ROWCOUNT");
	}

	public SQLChain RowGuidCol( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("ROWGUIDCOL");
	}

	public SQLChain Rule( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("RULE");
	}

	public SQLChain Save( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SAVE");
	}

	public SQLChain Schema( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SCHEMA");
	}

	public SQLChain SecurityAudit( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SECURITYAUDIT");
	}

	public SQLChain Select( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SELECT");
	}

	public SQLChain SemanticKeyPhraseTable( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SEMANTICKEYPHRASETABLE");
	}

	public SQLChain SemanticSimilarityDetailsTable( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SEMANTICSIMILARITYDETAILSTABLE");
	}

	public SQLChain SemanticSimilarityTable( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SEMANTICSIMILARITYTABLE");
	}

	public SQLChain Session_User( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SESSION_USER");
	}

	public SQLChain Set( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SET");
	}

	public SQLChain SetUser( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SETUSER");
	}

	public SQLChain Shutdown( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SHUTDOWN");
	}

	public SQLChain Some( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SOME");
	}

	public SQLChain Statistics( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("STATISTICS");
	}

	public SQLChain System_User( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("SYSTEM_USER");
	}

	public SQLChain Table( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TABLE");
	}

	public SQLChain TableSample( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TABLESAMPLE");
	}

	public SQLChain TextSize( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TEXTSIZE");
	}

	public SQLChain Then( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("THEN");
	}

	public SQLChain To( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TO");
	}

	public SQLChain Top( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TOP");
	}

	public SQLChain Tran( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TRAN");
	}

	public SQLChain Transaction( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TRANSACTION");
	}

	public SQLChain Trigger( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TRIGGER");
	}

	public SQLChain Truncate( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TRUNCATE");
	}

	public SQLChain Try_Convert( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TRY_CONVERT");
	}

	public SQLChain Tsequal( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("TSEQUAL");
	}

	public SQLChain Union( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("UNION");
	}

	public SQLChain Unique( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("UNIQUE");
	}

	public SQLChain UnPivot( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("UNPIVOT");
	}

	public SQLChain Update( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("UPDATE");
	}

	public SQLChain UpdateText( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("UPDATETEXT");
	}

	public SQLChain Use( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("USE");
	}

	public SQLChain User( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("USER");
	}

	public SQLChain Values( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("VALUES");
	}

	public SQLChain Varying( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("VARYING");
	}

	public SQLChain View( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("VIEW");
	}

	public SQLChain WaitFor( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WAITFOR");
	}

	public SQLChain When( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WHEN");
	}

	public SQLChain Where( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WHERE");
	}

	public SQLChain While( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WHILE");
	}

	public SQLChain With( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WITH");
	}

	public SQLChain WithinGroup( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WITHIN GROUP");
	}

	public SQLChain WriteText( char[] query = "", any ... )
	{
		VFormat(g_strSQLChain[1], sizeof(g_strSQLChain[]), query, 3);
		return this.Do("WRITETEXT");
	}
}
