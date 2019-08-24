#if defined _sqlchain_included
  #endinput
#endif
#define _sqlchain_included

#define MAX_QUERY_APPEND_LEN 		1024		// Oh whale

methodmap SQLChain < DataPack
{
	public SQLChain()
	{
		DataPack pack = new DataPack();
		pack.WriteCell(0);
		pack.WriteString("");
		return view_as< SQLChain >(pack);
	}

	public SQLChain Do( char[] appended )	// Private tags please ;-;
	{
		this.Reset();
		int len = this.ReadCell()+1;
		int appendlen = strlen(appended)+1;
		char[] myself = new char[len+appendlen];

		this.ReadString(myself, len);
		StrCat(myself, len+appendlen, appended);
		this.Reset(true);
		this.WriteCell(strlen(myself));
		this.WriteString(myself);

		return this;
	}

	public void Query( Database db, SQLQueryCallback callback, any data = 0, DBPriority prio = DBPrio_Normal )
	{
		this.Reset();
		int len = this.ReadCell()+1;
		char[] myself = new char[len];
		this.ReadString(myself, len);
		db.Query(callback, myself, data, prio);
	}

	public void Clear()
	{
		this.Reset(true);
		this.WriteCell(0);
		this.WriteString("");
	}

	public SQLChain Clone()
	{
		SQLChain chain = new SQLChain();
		this.Reset();
		int len = this.ReadCell()+1;
		char[] myself = new char[len];
		this.ReadString(myself, len);
		chain.WriteCell(strlen(myself));
		chain.WriteString(myself);
		return chain;
	}

	public SQLChain Add( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ADD %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain External( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXTERNAL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain All( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ALL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Fetch( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FETCH %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Alter( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ALTER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain File( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FILE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain And( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " AND %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain FillFactor( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FILLFACTOR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Any( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ANY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain For( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FOR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain As( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " AS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Foreign( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FOREIGN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Asc( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ASC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain FreeText( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FREETEXT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Authorization( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " AUTHORIZATION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain FreeTextTable( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FREETEXTTABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Backup( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BACKUP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain From( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FROM %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Begin( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BEGIN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Full( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FULL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Between( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BETWEEN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Function( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " FUNCTION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Break( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BREAK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Goto( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " GOTO %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Browse( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BROWSE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Grant( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " GRANT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Bulk( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BULK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Group( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " GROUP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain By( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " BY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Having( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " HAVING %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Cascade( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CASCADE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain HoldLock( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " HOLDLOCK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Case( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CASE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Identity( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IDENTITY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Check( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CHECK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain IDentity_Insert( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IDENTITY_INSERT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Checkpoint( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CHECKPOINT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain IdentityCol( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IDENTITYCOL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Close( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CLOSE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain If( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IF %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Clustered( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CLUSTERED %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain In( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Coalesce( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " COALESCE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Index( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " INDEX %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Collate( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " COLLATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Inner( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " INNER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Column( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " COLUMN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Insert( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " INSERT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Commit( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " COMMIT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Intersect( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " INTERSECT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Compute( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " COMPUTE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Into( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " INTO %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Constraint( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CONSTRAINT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Is( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " IS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Contains( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CONTAINS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Join( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " JOIN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain ContainsTable( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CONTAINSTABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Key( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " KEY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Continue( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CONTINUE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Kill( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " KILL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Convert( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CONVERT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Left( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " LEFT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Create( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CREATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Like( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " LIKE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Cross( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CROSS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Lineno( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " LINENO %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Current( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURRENT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Load( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " LOAD %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Current_Date( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURRENT_DATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Merge( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " MERGE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Current_Time( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURRENT_TIME %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain National( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NATIONAL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Current_Timestamp( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURRENT_TIMESTAMP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain NoCheck( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NOCHECK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Current_User( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURRENT_USER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain NonClustered( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NONCLUSTERED %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Cursor( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " CURSOR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Not( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NOT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Database( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DATABASE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Null( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NULL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Dbcc( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DBCC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain NullIf( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " NULLIF %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Deallocate( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DEALLOCATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Of( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OF %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Declare( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DECLARE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Off( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OFF %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Default( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DEFAULT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Offsets( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OFFSETS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Delete( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DELETE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain On( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ON %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Deny( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DENY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Open( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPEN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Desc( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DESC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain OpenDataSource( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPENDATASOURCE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Disk( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DISK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain OpenQuery( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPENQUERY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Distinct( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DISTINCT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Openrowset( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPENROWSET %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Distributed( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DISTRIBUTED %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Openxml( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPENXML %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Double( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DOUBLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Option( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OPTION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Drop( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DROP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Or( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Dump( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " DUMP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Order( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ORDER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Else( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ELSE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Outer( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OUTER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain End( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " END %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Over( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " OVER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Errlvl( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ERRLVL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Percent( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PERCENT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Escape( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ESCAPE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Pivot( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PIVOT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Except( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXCEPT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Plan( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PLAN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Exec( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXEC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Precision( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PRECISION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Execute( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXECUTE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Primary( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PRIMARY %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Exists( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXISTS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Print( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PRINT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Exit( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " EXIT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Proc( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PROC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Procedure( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PROCEDURE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Public( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " PUBLIC %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Raiserror( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RAISERROR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Read( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " READ %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain ReadText( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " READTEXT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Reconfigure( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RECONFIGURE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain References( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " REFERENCES %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Replication( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " REPLICATION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Restore( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RESTORE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Restrict( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RESTRICT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Return( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RETURN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Revert( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " REVERT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Revoke( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " REVOKE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Right( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RIGHT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Rollback( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ROLLBACK %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain RowCount( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ROWCOUNT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain RowGuidCol( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " ROWGUIDCOL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Rule( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " RULE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Save( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SAVE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Schema( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SCHEMA %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain SecurityAudit( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SECURITYAUDIT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Select( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SELECT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain SemanticKeyPhraseTable( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SEMANTICKEYPHRASETABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain SemanticSimilarityDetailsTable( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SEMANTICSIMILARITYDETAILSTABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain SemanticSimilarityTable( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SEMANTICSIMILARITYTABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Session_User( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SESSION_USER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Set( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SET %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain SetUser( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SETUSER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Shutdown( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SHUTDOWN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Some( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SOME %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Statistics( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " STATISTICS %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain System_User( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " SYSTEM_USER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Table( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TABLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain TableSample( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TABLESAMPLE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain TextSize( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TEXTSIZE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Then( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " THEN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain To( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TO %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Top( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TOP %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Tran( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TRAN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Transaction( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TRANSACTION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Trigger( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TRIGGER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Truncate( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TRUNCATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Try_Convert( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TRY_CONVERT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Tsequal( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " TSEQUAL %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Union( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " UNION %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Unique( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " UNIQUE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain UnPivot( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " UNPIVOT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Update( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " UPDATE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain UpdateText( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " UPDATETEXT %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Use( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " USE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain User( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " USER %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Values( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " VALUES %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Varying( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " VARYING %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain View( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " VIEW %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain WaitFor( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WAITFOR %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain When( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WHEN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain Where( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WHERE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain While( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WHILE %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain With( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WITH %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain WithinGroup( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WITHIN %s", buffer);
		return this.Do(buffer);
	}

	public SQLChain WriteText( char[] query = "", any ... )
	{
		char buffer[MAX_QUERY_APPEND_LEN];
		VFormat(buffer, sizeof(buffer), query, 3);
		Format(buffer, sizeof(buffer), " WRITETEXT %s", buffer);
		return this.Do(buffer);
	}
}
