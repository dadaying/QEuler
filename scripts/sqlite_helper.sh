#!/usr/bin/env bash

set -e

sqlite_file_path=$1
sql_cmd=$2

echo "Using sqlite file: ${sqlite_file_path}"
echo "Executing SQL command: ${sql_cmd}"

if [ ! -f "$sqlite_file_path" ]; then
    echo "Please provide the path of the sqlite file."
    exit 1
fi

echo "***************Executing SQL command***************"

sqlite3 ${sqlite_file_path} <<EOF
    ${sql_cmd}
EOF

echo "***************SQL command executed***************"