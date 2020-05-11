	function WarpClass(eID, tID, fID, ev)
	{
		var eObj = document.getElementById(eID);
		var tObj = document.getElementById(tID);
		var fObj = document.getElementById(fID);
		if (eObj && tObj)
		{
			if (!tObj.style.display || tObj.style.display == "block")
			{
				tObj.style.display = "none";
				eObj.className = "Warp";
				if (fObj)
				{
					fObj.style.display = "none";
				}
			}
			else
			{
				tObj.style.display = "block";
				eObj.className = "UnWarp";
				if (ev)
				{
					eval(ev);
				}
				if (fObj)
				{
					fObj.style.display = "block";
				}
			}
		}
	}
