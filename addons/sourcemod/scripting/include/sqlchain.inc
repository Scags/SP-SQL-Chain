#if defined _sqlchain_included
  #endinput
#endif
#define _sqlchain_included

static char g_strSQLChain[4096]; 	// Disgusting

methodmap SQLChain < DataPack
{
	public SQLChain()
	{
		DataPack pack = new DataPack();
		pack.WriteString("");
		return view_as< SQLChain >(pack);
	}

	public SQLChain Do( char[] replacestr, char[] query )	// Private tags please ;-;
	{
		this.Reset();
		this.ReadString(g_strSQLChain, sizeof(g_strSQLChain));
		Format(g_strSQLChain, sizeof(g_strSQLChain), "%s %s %s", g_strSQLChain, replacestr, query);
		this.Reset(true);
		this.WriteString(g_strSQLChain);
		return this;
	}

	public SQLChain Add( char[] query )
	{
		return this.Do("ADD", query);
	}

	public SQLChain External( char[] query )
	{
		return this.Do("EXTERNAL", query);
	}

	public SQLChain All( char[] query )
	{
		return this.Do("ALL", query);
	}

	public SQLChain Fetch( char[] query )
	{
		return this.Do("FETCH", query);
	}

	public SQLChain Alter( char[] query )
	{
		return this.Do("ALTER", query);
	}

	public SQLChain File( char[] query )
	{
		return this.Do("FILE", query);
	}

	public SQLChain And( char[] query )
	{
		return this.Do("AND", query);
	}

	public SQLChain FillFactor( char[] query )
	{
		return this.Do("FILLFACTOR", query);
	}

	public SQLChain Any( char[] query )
	{
		return this.Do("ANY", query);
	}

	public SQLChain For( char[] query )
	{
		return this.Do("FOR", query);
	}

	public SQLChain As( char[] query )
	{
		return this.Do("AS", query);
	}

	public SQLChain Foreign( char[] query )
	{
		return this.Do("FOREIGN", query);
	}

	public SQLChain Asc( char[] query )
	{
		return this.Do("ASC", query);
	}

	public SQLChain FreeText( char[] query )
	{
		return this.Do("FREETEXT", query);
	}

	public SQLChain Authorization( char[] query )
	{
		return this.Do("AUTHORIZATION", query);
	}

	public SQLChain FreeTextTable( char[] query )
	{
		return this.Do("FREETEXTTABLE", query);
	}

	public SQLChain Backup( char[] query )
	{
		return this.Do("BACKUP", query);
	}

	public SQLChain From( char[] query )
	{
		return this.Do("FROM", query);
	}

	public SQLChain Begin( char[] query )
	{
		return this.Do("BEGIN", query);
	}

	public SQLChain Full( char[] query )
	{
		return this.Do("FULL", query);
	}

	public SQLChain Between( char[] query )
	{
		return this.Do("BETWEEN", query);
	}

	public SQLChain Function( char[] query )
	{
		return this.Do("FUNCTION", query);
	}

	public SQLChain Break( char[] query )
	{
		return this.Do("BREAK", query);
	}

	public SQLChain Goto( char[] query )
	{
		return this.Do("GOTO", query);
	}

	public SQLChain Browse( char[] query )
	{
		return this.Do("BROWSE", query);
	}

	public SQLChain Grant( char[] query )
	{
		return this.Do("GRANT", query);
	}

	public SQLChain Bulk( char[] query )
	{
		return this.Do("BULK", query);
	}

	public SQLChain Group( char[] query )
	{
		return this.Do("GROUP", query);
	}

	public SQLChain By( char[] query )
	{
		return this.Do("BY", query);
	}

	public SQLChain Having( char[] query )
	{
		return this.Do("HAVING", query);
	}

	public SQLChain Cascade( char[] query )
	{
		return this.Do("CASCADE", query);
	}

	public SQLChain HoldLock( char[] query )
	{
		return this.Do("HOLDLOCK", query);
	}

	public SQLChain Case( char[] query )
	{
		return this.Do("CASE", query);
	}

	public SQLChain Identity( char[] query )
	{
		return this.Do("IDENTITY", query);
	}

	public SQLChain Check( char[] query )
	{
		return this.Do("CHECK", query);
	}

	public SQLChain IDentity_Insert( char[] query )
	{
		return this.Do("IDENTITY_INSERT", query);
	}

	public SQLChain Checkpoint( char[] query )
	{
		return this.Do("CHECKPOINT", query);
	}

	public SQLChain IdentityCol( char[] query )
	{
		return this.Do("IDENTITYCOL", query);
	}

	public SQLChain Close( char[] query )
	{
		return this.Do("CLOSE", query);
	}

	public SQLChain If( char[] query )
	{
		return this.Do("IF", query);
	}

	public SQLChain Clustered( char[] query )
	{
		return this.Do("CLUSTERED", query);
	}

	public SQLChain In( char[] query )
	{
		return this.Do("IN", query);
	}

	public SQLChain Coalesce( char[] query )
	{
		return this.Do("COALESCE", query);
	}

	public SQLChain Index( char[] query )
	{
		return this.Do("INDEX", query);
	}

	public SQLChain Collate( char[] query )
	{
		return this.Do("COLLATE", query);
	}

	public SQLChain Inner( char[] query )
	{
		return this.Do("INNER", query);
	}

	public SQLChain Column( char[] query )
	{
		return this.Do("COLUMN", query);
	}

	public SQLChain Insert( char[] query )
	{
		return this.Do("INSERT", query);
	}

	public SQLChain Commit( char[] query )
	{
		return this.Do("COMMIT", query);
	}

	public SQLChain Intersect( char[] query )
	{
		return this.Do("INTERSECT", query);
	}

	public SQLChain Compute( char[] query )
	{
		return this.Do("COMPUTE", query);
	}

	public SQLChain Into( char[] query )
	{
		return this.Do("INTO", query);
	}

	public SQLChain Constraint( char[] query )
	{
		return this.Do("CONSTRAINT", query);
	}

	public SQLChain Is( char[] query )
	{
		return this.Do("IS", query);
	}

	public SQLChain Contains( char[] query )
	{
		return this.Do("CONTAINS", query);
	}

	public SQLChain Join( char[] query )
	{
		return this.Do("JOIN", query);
	}

	public SQLChain ContainsTable( char[] query )
	{
		return this.Do("CONTAINSTABLE", query);
	}

	public SQLChain Key( char[] query )
	{
		return this.Do("KEY", query);
	}

	public SQLChain Continue( char[] query )
	{
		return this.Do("CONTINUE", query);
	}

	public SQLChain Kill( char[] query )
	{
		return this.Do("KILL", query);
	}

	public SQLChain Convert( char[] query )
	{
		return this.Do("CONVERT", query);
	}

	public SQLChain Left( char[] query )
	{
		return this.Do("LEFT", query);
	}

	public SQLChain Create( char[] query )
	{
		return this.Do("CREATE", query);
	}

	public SQLChain Like( char[] query )
	{
		return this.Do("LIKE", query);
	}

	public SQLChain Cross( char[] query )
	{
		return this.Do("CROSS", query);
	}

	public SQLChain Lineno( char[] query )
	{
		return this.Do("LINENO", query);
	}

	public SQLChain Current( char[] query )
	{
		return this.Do("CURRENT", query);
	}

	public SQLChain Load( char[] query )
	{
		return this.Do("LOAD", query);
	}

	public SQLChain Current_Date( char[] query )
	{
		return this.Do("CURRENT_DATE", query);
	}

	public SQLChain Merge( char[] query )
	{
		return this.Do("MERGE", query);
	}

	public SQLChain Current_Time( char[] query )
	{
		return this.Do("CURRENT_TIME", query);
	}

	public SQLChain National( char[] query )
	{
		return this.Do("NATIONAL", query);
	}

	public SQLChain Current_Timestamp( char[] query )
	{
		return this.Do("CURRENT_TIMESTAMP", query);
	}

	public SQLChain NoCheck( char[] query )
	{
		return this.Do("NOCHECK", query);
	}

	public SQLChain Current_User( char[] query )
	{
		return this.Do("CURRENT_USER", query);
	}

	public SQLChain NonClustered( char[] query )
	{
		return this.Do("NONCLUSTERED", query);
	}

	public SQLChain Cursor( char[] query )
	{
		return this.Do("CURSOR", query);
	}

	public SQLChain Not( char[] query )
	{
		return this.Do("NOT", query);
	}

	public SQLChain Database( char[] query )
	{
		return this.Do("DATABASE", query);
	}

	public SQLChain Null( char[] query )
	{
		return this.Do("NULL", query);
	}

	public SQLChain Dbcc( char[] query )
	{
		return this.Do("DBCC", query);
	}

	public SQLChain NullIf( char[] query )
	{
		return this.Do("NULLIF", query);
	}

	public SQLChain Deallocate( char[] query )
	{
		return this.Do("DEALLOCATE", query);
	}

	public SQLChain Of( char[] query )
	{
		return this.Do("OF", query);
	}

	public SQLChain Declare( char[] query )
	{
		return this.Do("DECLARE", query);
	}

	public SQLChain Off( char[] query )
	{
		return this.Do("OFF", query);
	}

	public SQLChain Default( char[] query )
	{
		return this.Do("DEFAULT", query);
	}

	public SQLChain Offsets( char[] query )
	{
		return this.Do("OFFSETS", query);
	}

	public SQLChain Delete( char[] query )
	{
		return this.Do("DELETE", query);
	}

	public SQLChain On( char[] query )
	{
		return this.Do("ON", query);
	}

	public SQLChain Deny( char[] query )
	{
		return this.Do("DENY", query);
	}

	public SQLChain Open( char[] query )
	{
		return this.Do("OPEN", query);
	}

	public SQLChain Desc( char[] query )
	{
		return this.Do("DESC", query);
	}

	public SQLChain OpenDataSource( char[] query )
	{
		return this.Do("OPENDATASOURCE", query);
	}

	public SQLChain Disk( char[] query )
	{
		return this.Do("DISK", query);
	}

	public SQLChain OpenQuery( char[] query )
	{
		return this.Do("OPENQUERY", query);
	}

	public SQLChain Distinct( char[] query )
	{
		return this.Do("DISTINCT", query);
	}

	public SQLChain Openrowset( char[] query )
	{
		return this.Do("OPENROWSET", query);
	}

	public SQLChain Distributed( char[] query )
	{
		return this.Do("DISTRIBUTED", query);
	}

	public SQLChain Openxml( char[] query )
	{
		return this.Do("OPENXML", query);
	}

	public SQLChain Double( char[] query )
	{
		return this.Do("DOUBLE", query);
	}

	public SQLChain Option( char[] query )
	{
		return this.Do("OPTION", query);
	}

	public SQLChain Drop( char[] query )
	{
		return this.Do("DROP", query);
	}

	public SQLChain Or( char[] query )
	{
		return this.Do("OR", query);
	}

	public SQLChain Dump( char[] query )
	{
		return this.Do("DUMP", query);
	}

	public SQLChain Order( char[] query )
	{
		return this.Do("ORDER", query);
	}

	public SQLChain Else( char[] query )
	{
		return this.Do("ELSE", query);
	}

	public SQLChain Outer( char[] query )
	{
		return this.Do("OUTER", query);
	}

	public SQLChain End( char[] query )
	{
		return this.Do("END", query);
	}

	public SQLChain Over( char[] query )
	{
		return this.Do("OVER", query);
	}

	public SQLChain Errlvl( char[] query )
	{
		return this.Do("ERRLVL", query);
	}

	public SQLChain Percent( char[] query )
	{
		return this.Do("PERCENT", query);
	}

	public SQLChain Escape( char[] query )
	{
		return this.Do("ESCAPE", query);
	}

	public SQLChain Pivot( char[] query )
	{
		return this.Do("PIVOT", query);
	}

	public SQLChain Except( char[] query )
	{
		return this.Do("EXCEPT", query);
	}

	public SQLChain Plan( char[] query )
	{
		return this.Do("PLAN", query);
	}

	public SQLChain Exec( char[] query )
	{
		return this.Do("EXEC", query);
	}

	public SQLChain Precision( char[] query )
	{
		return this.Do("PRECISION", query);
	}

	public SQLChain Execute( char[] query )
	{
		return this.Do("EXECUTE", query);
	}

	public SQLChain Primary( char[] query )
	{
		return this.Do("PRIMARY", query);
	}

	public SQLChain Exists( char[] query )
	{
		return this.Do("EXISTS", query);
	}

	public SQLChain Print( char[] query )
	{
		return this.Do("PRINT", query);
	}

	public SQLChain Exit( char[] query )
	{
		return this.Do("EXIT", query);
	}

	public SQLChain Proc( char[] query )
	{
		return this.Do("PROC", query);
	}

	public SQLChain Procedure( char[] query )
	{
		return this.Do("PROCEDURE", query);
	}

	public SQLChain Public( char[] query )
	{
		return this.Do("PUBLIC", query);
	}

	public SQLChain Raiserror( char[] query )
	{
		return this.Do("RAISERROR", query);
	}

	public SQLChain Read( char[] query )
	{
		return this.Do("READ", query);
	}

	public SQLChain ReadText( char[] query )
	{
		return this.Do("READTEXT", query);
	}

	public SQLChain Reconfigure( char[] query )
	{
		return this.Do("RECONFIGURE", query);
	}

	public SQLChain References( char[] query )
	{
		return this.Do("REFERENCES", query);
	}

	public SQLChain Replication( char[] query )
	{
		return this.Do("REPLICATION", query);
	}

	public SQLChain Restore( char[] query )
	{
		return this.Do("RESTORE", query);
	}

	public SQLChain Restrict( char[] query )
	{
		return this.Do("RESTRICT", query);
	}

	public SQLChain Return( char[] query )
	{
		return this.Do("RETURN", query);
	}

	public SQLChain Revert( char[] query )
	{
		return this.Do("REVERT", query);
	}

	public SQLChain Revoke( char[] query )
	{
		return this.Do("REVOKE", query);
	}

	public SQLChain Right( char[] query )
	{
		return this.Do("RIGHT", query);
	}

	public SQLChain Rollback( char[] query )
	{
		return this.Do("ROLLBACK", query);
	}

	public SQLChain RowCount( char[] query )
	{
		return this.Do("ROWCOUNT", query);
	}

	public SQLChain RowGuidCol( char[] query )
	{
		return this.Do("ROWGUIDCOL", query);
	}

	public SQLChain Rule( char[] query )
	{
		return this.Do("RULE", query);
	}

	public SQLChain Save( char[] query )
	{
		return this.Do("SAVE", query);
	}

	public SQLChain Schema( char[] query )
	{
		return this.Do("SCHEMA", query);
	}

	public SQLChain SecurityAudit( char[] query )
	{
		return this.Do("SECURITYAUDIT", query);
	}

	public SQLChain Select( char[] query )
	{
		return this.Do("SELECT", query);
	}

	public SQLChain SemanticKeyPhraseTable( char[] query )
	{
		return this.Do("SEMANTICKEYPHRASETABLE", query);
	}

	public SQLChain SemanticSimilarityDetailsTable( char[] query )
	{
		return this.Do("SEMANTICSIMILARITYDETAILSTABLE", query);
	}

	public SQLChain SemanticSimilarityTable( char[] query )
	{
		return this.Do("SEMANTICSIMILARITYTABLE", query);
	}

	public SQLChain Session_User( char[] query )
	{
		return this.Do("SESSION_USER", query);
	}

	public SQLChain Set( char[] query )
	{
		return this.Do("SET", query);
	}

	public SQLChain SetUser( char[] query )
	{
		return this.Do("SETUSER", query);
	}

	public SQLChain Shutdown( char[] query )
	{
		return this.Do("SHUTDOWN", query);
	}

	public SQLChain Some( char[] query )
	{
		return this.Do("SOME", query);
	}

	public SQLChain Statistics( char[] query )
	{
		return this.Do("STATISTICS", query);
	}

	public SQLChain System_User( char[] query )
	{
		return this.Do("SYSTEM_USER", query);
	}

	public SQLChain Table( char[] query )
	{
		return this.Do("TABLE", query);
	}

	public SQLChain TableSample( char[] query )
	{
		return this.Do("TABLESAMPLE", query);
	}

	public SQLChain TextSize( char[] query )
	{
		return this.Do("TEXTSIZE", query);
	}

	public SQLChain Then( char[] query )
	{
		return this.Do("THEN", query);
	}

	public SQLChain To( char[] query )
	{
		return this.Do("TO", query);
	}

	public SQLChain Top( char[] query )
	{
		return this.Do("TOP", query);
	}

	public SQLChain Tran( char[] query )
	{
		return this.Do("TRAN", query);
	}

	public SQLChain Transaction( char[] query )
	{
		return this.Do("TRANSACTION", query);
	}

	public SQLChain Trigger( char[] query )
	{
		return this.Do("TRIGGER", query);
	}

	public SQLChain Truncate( char[] query )
	{
		return this.Do("TRUNCATE", query);
	}

	public SQLChain Try_Convert( char[] query )
	{
		return this.Do("TRY_CONVERT", query);
	}

	public SQLChain Tsequal( char[] query )
	{
		return this.Do("TSEQUAL", query);
	}

	public SQLChain Union( char[] query )
	{
		return this.Do("UNION", query);
	}

	public SQLChain Unique( char[] query )
	{
		return this.Do("UNIQUE", query);
	}

	public SQLChain UnPivot( char[] query )
	{
		return this.Do("UNPIVOT", query);
	}

	public SQLChain Update( char[] query )
	{
		return this.Do("UPDATE", query);
	}

	public SQLChain UpdateText( char[] query )
	{
		return this.Do("UPDATETEXT", query);
	}

	public SQLChain Use( char[] query )
	{
		return this.Do("USE", query);
	}

	public SQLChain User( char[] query )
	{
		return this.Do("USER", query);
	}

	public SQLChain Values( char[] query )
	{
		return this.Do("VALUES", query);
	}

	public SQLChain Varying( char[] query )
	{
		return this.Do("VARYING", query);
	}

	public SQLChain View( char[] query )
	{
		return this.Do("VIEW", query);
	}

	public SQLChain WaitFor( char[] query )
	{
		return this.Do("WAITFOR", query);
	}

	public SQLChain When( char[] query )
	{
		return this.Do("WHEN", query);
	}

	public SQLChain Where( char[] query )
	{
		return this.Do("WHERE", query);
	}

	public SQLChain While( char[] query )
	{
		return this.Do("WHILE", query);
	}

	public SQLChain With( char[] query )
	{
		return this.Do("WITH", query);
	}

	public SQLChain WithinGroup( char[] query )
	{
		return this.Do("WITHIN GROUP", query);
	}

	public SQLChain WriteText( char[] query )
	{
		return this.Do("WRITETEXT", query);
	}

	public void Query( Database db, SQLQueryCallback callback, any data = 0, DBPriority prio = DBPrio_Normal )
	{
		this.Reset();
		this.ReadString(g_strSQLChain, sizeof(g_strSQLChain));
		db.Query(callback, g_strSQLChain, data, prio);
	}

	public void Clear()
	{
		this.Reset(true);
	}
}

