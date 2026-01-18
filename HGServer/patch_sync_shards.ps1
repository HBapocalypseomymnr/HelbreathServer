$path = 'd:\HelbreathServer\HGServer\Game.cpp'
$content = Get-Content $path -Raw -Encoding Default

$search = '	m_pClientList[iClientH]->read_shards_data();
	m_pClientList[iClientH]->read_fragments_data();
}'

$insert = @"
	m_pClientList[iClientH]->read_shards_data();
	m_pClientList[iClientH]->read_fragments_data();

	// FIX: Send Shards to client
	for (int i = 0; i < 13; i++) {
		for (int x = 0; x < 17; x++) {
			if (m_pClientList[iClientH]->m_pShards[i][x] != 0 && 
				m_pClientList[iClientH]->m_pShards[i][x]->iCount > 0) {
			   SendNotifyMsg(0, iClientH, 0x0A71 /*msg_shard*/, 
							m_pClientList[iClientH]->m_pShards[i][x]->dwType,
							m_pClientList[iClientH]->m_pShards[i][x]->dwValue,
							m_pClientList[iClientH]->m_pShards[i][x]->iCount,
							m_pClientList[iClientH]->m_pShards[i][x]->cName, 0, 0, 0, 0, 0, 0,
							m_pClientList[iClientH]->m_pShards[i][x]->cDesc);
			}
		}
	}
}
"@

# Note: Using hardcoded 0x0A71 for msg_shard to avoid dependency on define visibility if placed before include headers, 
# though Game.cpp should see it. Using comment to clarify.

if ($content -match [regex]::Escape($search)) {
    $newContent = $content.Replace($search, $insert)
    Set-Content $path -Value $newContent -Encoding Default -NoNewline
    Write-Host "Success"
}
else {
    Write-Host "Search string not found"
}
