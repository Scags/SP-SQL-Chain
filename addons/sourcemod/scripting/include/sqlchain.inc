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
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ADD %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ADD");
	}

	public SQLChain External( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXTERNAL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXTERNAL");
	}

	public SQLChain All( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ALL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ALL");
	}

	public SQLChain Fetch( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FETCH %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FETCH");
	}

	public SQLChain Alter( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ALTER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ALTER");
	}

	public SQLChain File( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FILE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FILE");
	}

	public SQLChain And( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " AND %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" AND");
	}

	public SQLChain FillFactor( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FILLFACTOR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FILLFACTOR");
	}

	public SQLChain Any( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ANY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ANY");
	}

	public SQLChain For( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FOR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FOR");
	}

	public SQLChain As( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " AS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" AS");
	}

	public SQLChain Foreign( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FOREIGN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FOREIGN");
	}

	public SQLChain Asc( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ASC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ASC");
	}

	public SQLChain FreeText( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FREETEXT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FREETEXT");
	}

	public SQLChain Authorization( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " AUTHORIZATION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" AUTHORIZATION");
	}

	public SQLChain FreeTextTable( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FREETEXTTABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FREETEXTTABLE");
	}

	public SQLChain Backup( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BACKUP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BACKUP");
	}

	public SQLChain From( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FROM %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FROM");
	}

	public SQLChain Begin( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BEGIN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BEGIN");
	}

	public SQLChain Full( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FULL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FULL");
	}

	public SQLChain Between( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BETWEEN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BETWEEN");
	}

	public SQLChain Function( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " FUNCTION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" FUNCTION");
	}

	public SQLChain Break( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BREAK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BREAK");
	}

	public SQLChain Goto( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " GOTO %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" GOTO");
	}

	public SQLChain Browse( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BROWSE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BROWSE");
	}

	public SQLChain Grant( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " GRANT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" GRANT");
	}

	public SQLChain Bulk( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BULK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BULK");
	}

	public SQLChain Group( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " GROUP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" GROUP");
	}

	public SQLChain By( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " BY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" BY");
	}

	public SQLChain Having( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " HAVING %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" HAVING");
	}

	public SQLChain Cascade( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CASCADE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CASCADE");
	}

	public SQLChain HoldLock( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " HOLDLOCK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" HOLDLOCK");
	}

	public SQLChain Case( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CASE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CASE");
	}

	public SQLChain Identity( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IDENTITY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IDENTITY");
	}

	public SQLChain Check( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CHECK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CHECK");
	}

	public SQLChain IDentity_Insert( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IDENTITY_INSERT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IDENTITY_INSERT");
	}

	public SQLChain Checkpoint( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CHECKPOINT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CHECKPOINT");
	}

	public SQLChain IdentityCol( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IDENTITYCOL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IDENTITYCOL");
	}

	public SQLChain Close( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CLOSE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CLOSE");
	}

	public SQLChain If( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IF %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IF");
	}

	public SQLChain Clustered( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CLUSTERED %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CLUSTERED");
	}

	public SQLChain In( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IN");
	}

	public SQLChain Coalesce( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " COALESCE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" COALESCE");
	}

	public SQLChain Index( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " INDEX %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" INDEX");
	}

	public SQLChain Collate( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " COLLATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" COLLATE");
	}

	public SQLChain Inner( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " INNER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" INNER");
	}

	public SQLChain Column( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " COLUMN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" COLUMN");
	}

	public SQLChain Insert( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " INSERT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" INSERT");
	}

	public SQLChain Commit( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " COMMIT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" COMMIT");
	}

	public SQLChain Intersect( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " INTERSECT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" INTERSECT");
	}

	public SQLChain Compute( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " COMPUTE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" COMPUTE");
	}

	public SQLChain Into( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " INTO %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" INTO");
	}

	public SQLChain Constraint( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CONSTRAINT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CONSTRAINT");
	}

	public SQLChain Is( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " IS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" IS");
	}

	public SQLChain Contains( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CONTAINS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CONTAINS");
	}

	public SQLChain Join( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " JOIN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" JOIN");
	}

	public SQLChain ContainsTable( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CONTAINSTABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CONTAINSTABLE");
	}

	public SQLChain Key( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " KEY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" KEY");
	}

	public SQLChain Continue( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CONTINUE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CONTINUE");
	}

	public SQLChain Kill( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " KILL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" KILL");
	}

	public SQLChain Convert( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CONVERT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CONVERT");
	}

	public SQLChain Left( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " LEFT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" LEFT");
	}

	public SQLChain Create( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CREATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CREATE");
	}

	public SQLChain Like( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " LIKE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" LIKE");
	}

	public SQLChain Cross( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CROSS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CROSS");
	}

	public SQLChain LineNo( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " LINENO %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" LINENO");
	}

	public SQLChain Current( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURRENT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURRENT");
	}

	public SQLChain Load( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " LOAD %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" LOAD");
	}

	public SQLChain Current_Date( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURRENT_DATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURRENT_DATE");
	}

	public SQLChain Merge( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " MERGE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" MERGE");
	}

	public SQLChain Current_Time( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURRENT_TIME %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURRENT_TIME");
	}

	public SQLChain National( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NATIONAL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NATIONAL");
	}

	public SQLChain Current_Timestamp( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURRENT_TIMESTAMP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURRENT_TIMESTAMP");
	}

	public SQLChain NoCheck( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NOCHECK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NOCHECK");
	}

	public SQLChain Current_User( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURRENT_USER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURRENT_USER");
	}

	public SQLChain NonClustered( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NONCLUSTERED %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NONCLUSTERED");
	}

	public SQLChain Cursor( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " CURSOR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" CURSOR");
	}

	public SQLChain Not( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NOT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NOT");
	}

	public SQLChain Database( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DATABASE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DATABASE");
	}

	public SQLChain Null( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NULL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NULL");
	}

	public SQLChain Dbcc( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DBCC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DBCC");
	}

	public SQLChain NullIf( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " NULLIF %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" NULLIF");
	}

	public SQLChain Deallocate( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DEALLOCATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DEALLOCATE");
	}

	public SQLChain Of( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OF %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OF");
	}

	public SQLChain Declare( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DECLARE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DECLARE");
	}

	public SQLChain Off( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OFF %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OFF");
	}

	public SQLChain Default( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DEFAULT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DEFAULT");
	}

	public SQLChain Offsets( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OFFSETS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OFFSETS");
	}

	public SQLChain Delete( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DELETE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DELETE");
	}

	public SQLChain On( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ON %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ON");
	}

	public SQLChain Deny( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DENY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DENY");
	}

	public SQLChain Open( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPEN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPEN");
	}

	public SQLChain Desc( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DESC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DESC");
	}

	public SQLChain OpenDataSource( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPENDATASOURCE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPENDATASOURCE");
	}

	public SQLChain Disk( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DISK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DISK");
	}

	public SQLChain OpenQuery( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPENQUERY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPENQUERY");
	}

	public SQLChain Distinct( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DISTINCT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DISTINCT");
	}

	public SQLChain Openrowset( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPENROWSET %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPENROWSET");
	}

	public SQLChain Distributed( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DISTRIBUTED %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DISTRIBUTED");
	}

	public SQLChain Openxml( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPENXML %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPENXML");
	}

	public SQLChain Double( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DOUBLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DOUBLE");
	}

	public SQLChain Option( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OPTION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OPTION");
	}

	public SQLChain Drop( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DROP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DROP");
	}

	public SQLChain Or( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OR");
	}

	public SQLChain Dump( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " DUMP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" DUMP");
	}

	public SQLChain Order( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ORDER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ORDER");
	}

	public SQLChain Else( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ELSE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ELSE");
	}

	public SQLChain Outer( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OUTER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OUTER");
	}

	public SQLChain End( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " END %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" END");
	}

	public SQLChain Over( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " OVER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" OVER");
	}

	public SQLChain Errlvl( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ERRLVL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ERRLVL");
	}

	public SQLChain Percent( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PERCENT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PERCENT");
	}

	public SQLChain Escape( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ESCAPE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ESCAPE");
	}

	public SQLChain Pivot( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PIVOT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PIVOT");
	}

	public SQLChain Except( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXCEPT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXCEPT");
	}

	public SQLChain Plan( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PLAN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PLAN");
	}

	public SQLChain Exec( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXEC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXEC");
	}

	public SQLChain Precision( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PRECISION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PRECISION");
	}

	public SQLChain Execute( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXECUTE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXECUTE");
	}

	public SQLChain Primary( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PRIMARY %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PRIMARY");
	}

	public SQLChain Exists( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXISTS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXISTS");
	}

	public SQLChain Print( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PRINT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PRINT");
	}

	public SQLChain Exit( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " EXIT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" EXIT");
	}

	public SQLChain Proc( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PROC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PROC");
	}

	public SQLChain Procedure( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PROCEDURE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PROCEDURE");
	}

	public SQLChain Public( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " PUBLIC %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" PUBLIC");
	}

	public SQLChain Raiserror( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RAISERROR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RAISERROR");
	}

	public SQLChain Read( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " READ %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" READ");
	}

	public SQLChain ReadText( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " READTEXT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" READTEXT");
	}

	public SQLChain Reconfigure( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RECONFIGURE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RECONFIGURE");
	}

	public SQLChain References( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " REFERENCES %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" REFERENCES");
	}

	public SQLChain Replication( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " REPLICATION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" REPLICATION");
	}

	public SQLChain Restore( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RESTORE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RESTORE");
	}

	public SQLChain Restrict( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RESTRICT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RESTRICT");
	}

	public SQLChain Return( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RETURN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RETURN");
	}

	public SQLChain Revert( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " REVERT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" REVERT");
	}

	public SQLChain Revoke( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " REVOKE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" REVOKE");
	}

	public SQLChain Right( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RIGHT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RIGHT");
	}

	public SQLChain Rollback( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ROLLBACK %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ROLLBACK");
	}

	public SQLChain RowCount( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ROWCOUNT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ROWCOUNT");
	}

	public SQLChain RowGuidCol( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " ROWGUIDCOL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" ROWGUIDCOL");
	}

	public SQLChain Rule( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " RULE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" RULE");
	}

	public SQLChain Save( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SAVE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SAVE");
	}

	public SQLChain Schema( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SCHEMA %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SCHEMA");
	}

	public SQLChain SecurityAudit( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SECURITYAUDIT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SECURITYAUDIT");
	}

	public SQLChain Select( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SELECT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SELECT");
	}

	public SQLChain SemanticKeyPhraseTable( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SEMANTICKEYPHRASETABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SEMANTICKEYPHRASETABLE");
	}

	public SQLChain SemanticSimilarityDetailsTable( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SEMANTICSIMILARITYDETAILSTABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SEMANTICSIMILARITYDETAILSTABLE");
	}

	public SQLChain SemanticSimilarityTable( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SEMANTICSIMILARITYTABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SEMANTICSIMILARITYTABLE");
	}

	public SQLChain Session_User( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SESSION_USER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SESSION_USER");
	}

	public SQLChain Set( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SET %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SET");
	}

	public SQLChain SetUser( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SETUSER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SETUSER");
	}

	public SQLChain Shutdown( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SHUTDOWN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SHUTDOWN");
	}

	public SQLChain Some( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SOME %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SOME");
	}

	public SQLChain Statistics( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " STATISTICS %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" STATISTICS");
	}

	public SQLChain System_User( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " SYSTEM_USER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" SYSTEM_USER");
	}

	public SQLChain Table( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TABLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TABLE");
	}

	public SQLChain TableSample( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TABLESAMPLE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TABLESAMPLE");
	}

	public SQLChain TextSize( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TEXTSIZE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TEXTSIZE");
	}

	public SQLChain Then( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " THEN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" THEN");
	}

	public SQLChain To( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TO %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TO");
	}

	public SQLChain Top( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TOP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TOP");
	}

	public SQLChain Tran( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TRAN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TRAN");
	}

	public SQLChain Transaction( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TRANSACTION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TRANSACTION");
	}

	public SQLChain Trigger( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TRIGGER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TRIGGER");
	}

	public SQLChain Truncate( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TRUNCATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TRUNCATE");
	}

	public SQLChain Try_Convert( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TRY_CONVERT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TRY_CONVERT");
	}

	public SQLChain Tsequal( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " TSEQUAL %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" TSEQUAL");
	}

	public SQLChain Union( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " UNION %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" UNION");
	}

	public SQLChain Unique( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " UNIQUE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" UNIQUE");
	}

	public SQLChain UnPivot( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " UNPIVOT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" UNPIVOT");
	}

	public SQLChain Update( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " UPDATE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" UPDATE");
	}

	public SQLChain UpdateText( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " UPDATETEXT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" UPDATETEXT");
	}

	public SQLChain Use( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " USE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" USE");
	}

	public SQLChain User( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " USER %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" USER");
	}

	public SQLChain Values( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " VALUES %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" VALUES");
	}

	public SQLChain Varying( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " VARYING %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" VARYING");
	}

	public SQLChain View( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " VIEW %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" VIEW");
	}

	public SQLChain WaitFor( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WAITFOR %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WAITFOR");
	}

	public SQLChain When( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WHEN %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WHEN");
	}

	public SQLChain Where( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WHERE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WHERE");
	}

	public SQLChain While( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WHILE %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WHILE");
	}

	public SQLChain With( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WITH %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WITH");
	}

	public SQLChain WithinGroup( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WITHIN GROUP %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WITHIN GROUP");
	}

	public SQLChain WriteText( char[] query = "", any ... )
	{
		if (query[0] != '\0')
		{
			char buffer[MAX_QUERY_APPEND_LEN];
			VFormat(buffer, sizeof(buffer), query, 3);
			Format(buffer, sizeof(buffer), " WRITETEXT %s", buffer);
			return this.Do(buffer);
		}
		else return this.Do(" WRITETEXT");
	}
}
