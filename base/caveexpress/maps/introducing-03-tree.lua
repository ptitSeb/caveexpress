function getName()
	return "Tree"
end

function onMapLoaded()
end

function initMap()
	-- get the current map context
	local map = Map.get()
	map:addTile("tile-rock-slope-right-02", 0, 0)
	map:addTile("tile-background-04", 0, 1)
	map:addTile("tile-background-02", 0, 2)
	map:addTile("tile-background-02", 0, 3)
	map:addTile("tile-ground-01", 0, 5)
	map:addTile("tile-background-03", 0, 6)
	map:addTile("tile-ground-01", 0, 8)
	map:addTile("tile-rock-big-01", 0, 9)
	map:addTile("tile-rock-02", 0, 11)
	map:addTile("tile-background-04", 1, 0)
	map:addTile("tile-background-02", 1, 1)
	map:addTile("tile-background-01", 1, 2)
	map:addTile("tile-background-02", 1, 3)
	map:addTile("tile-background-window-02", 1, 4)
	map:addTile("tile-ground-03", 1, 5)
	map:addTile("tile-background-01", 1, 6)
	map:addTile("liane-01", 1, 6)
	map:addTile("tile-background-window-01", 1, 7)
	map:addTile("tile-ground-03", 1, 8)
	map:addTile("tile-rock-02", 1, 11)
	map:addTile("tile-rock-shim-01", 2, 0)
	map:addTile("tile-background-04", 2, 1)
	map:addTile("tile-background-01", 2, 2)
	map:addTile("tile-background-02", 2, 3)
	map:addTile("tile-background-cave-art-01", 2, 4)
	map:addTile("tile-background-big-01", 2, 5)
	map:addTile("tile-background-02", 2, 7)
	map:addTile("tile-ground-02", 2, 8)
	map:addTile("tile-rock-02", 2, 9)
	map:addTile("tile-rock-01", 2, 10)
	map:addTile("tile-rock-01", 2, 11)
	map:addTile("tile-background-04", 3, 0)
	map:addTile("tile-background-big-01", 3, 1)
	map:addTile("tile-background-03", 3, 3)
	map:addTile("tile-background-02", 3, 4)
	map:addTile("tile-background-02", 3, 7)
	map:addTile("tile-ground-03", 3, 8)
	map:addTile("tile-rock-03", 3, 9)
	map:addTile("tile-rock-big-01", 3, 10)
	map:addTile("tile-background-01", 4, 0)
	map:addTile("liane-01", 4, 0)
	map:addTile("tile-background-02", 4, 3)
	map:addTile("tile-background-big-01", 4, 4)
	map:addTile("tile-background-02", 4, 6)
	map:addTile("tile-background-02", 4, 7)
	map:addTile("tile-ground-03", 4, 8)
	map:addTile("tile-rock-01", 4, 9)
	map:addTile("tile-background-01", 5, 0)
	map:addTile("liane-01", 5, 0)
	map:addTile("tile-background-01", 5, 1)
	map:addTile("tile-background-03", 5, 2)
	map:addTile("tile-background-02", 5, 3)
	map:addTile("tile-background-01", 5, 6)
	map:addTile("tile-background-cave-art-01", 5, 7)
	map:addTile("tile-ground-01", 5, 8)
	map:addTile("tile-rock-02", 5, 9)
	map:addTile("tile-rock-03", 5, 10)
	map:addTile("tile-rock-02", 5, 11)
	map:addTile("tile-background-03", 6, 0)
	map:addTile("tile-background-01", 6, 1)
	map:addTile("tile-background-01", 6, 2)
	map:addTile("tile-background-01", 6, 3)
	map:addTile("tile-background-01", 6, 4)
	map:addTile("tile-background-03", 6, 5)
	map:addTile("tile-background-03", 6, 6)
	map:addTile("tile-background-03", 6, 7)
	map:addTile("tile-packagetarget-rock-01-idle", 6, 8)
	map:addTile("tile-rock-01", 6, 9)
	map:addTile("tile-rock-02", 6, 10)
	map:addTile("tile-rock-01", 6, 11)
	map:addTile("tile-background-01", 7, 0)
	map:addTile("tile-background-01", 7, 1)
	map:addTile("tile-background-02", 7, 2)
	map:addTile("tile-background-03", 7, 3)
	map:addTile("tile-background-03", 7, 4)
	map:addTile("tile-background-02", 7, 5)
	map:addTile("tile-background-03", 7, 6)
	map:addTile("tile-background-cave-art-01", 7, 7)
	map:addTile("tile-ground-02", 7, 8)
	map:addTile("tile-rock-03", 7, 9)
	map:addTile("tile-rock-01", 7, 10)
	map:addTile("tile-rock-03", 7, 11)
	map:addTile("tile-background-01", 8, 0)
	map:addTile("liane-01", 8, 0)
	map:addTile("tile-background-big-01", 8, 1)
	map:addTile("tile-background-01", 8, 3)
	map:addTile("tile-background-01", 8, 4)
	map:addTile("tile-ground-05", 8, 5)
	map:addTile("tile-background-01", 8, 6)
	map:addTile("tile-background-03", 8, 7)
	map:addTile("tile-ground-02", 8, 8)
	map:addTile("tile-rock-big-01", 8, 9)
	map:addTile("tile-rock-02", 8, 11)
	map:addTile("tile-rock-slope-left-02", 9, 0)
	map:addTile("tile-background-02", 9, 3)
	map:addTile("tile-background-03", 9, 4)
	map:addTile("tile-ground-06", 9, 5)
	map:addTile("tile-background-03", 9, 6)
	map:addTile("tile-background-01", 9, 7)
	map:addTile("tile-ground-03", 9, 8)
	map:addTile("tile-rock-02", 9, 11)
	map:addTile("tile-rock-03", 10, 0)
	map:addTile("tile-rock-slope-left-02", 10, 1)
	map:addTile("tile-background-01", 10, 2)
	map:addTile("tile-background-03", 10, 3)
	map:addTile("tile-background-01", 10, 4)
	map:addTile("tile-ground-05", 10, 5)
	map:addTile("tile-background-01", 10, 6)
	map:addTile("tile-background-01", 10, 7)
	map:addTile("tile-ground-02", 10, 8)
	map:addTile("tile-rock-01", 10, 9)
	map:addTile("tile-rock-big-01", 10, 10)
	map:addTile("tile-rock-01", 11, 0)
	map:addTile("tile-rock-03", 11, 1)
	map:addTile("tile-rock-slope-left-02", 11, 2)
	map:addTile("tile-background-04", 11, 3)
	map:addTile("tile-background-01", 11, 4)
	map:addTile("tile-ground-05", 11, 5)
	map:addTile("tile-background-03", 11, 6)
	map:addTile("tile-background-03", 11, 7)
	map:addTile("tile-ground-03", 11, 8)
	map:addTile("tile-rock-03", 11, 9)
	map:addTile("tile-rock-big-01", 12, 0)
	map:addTile("tile-rock-01", 12, 2)
	map:addTile("tile-rock-02", 12, 3)
	map:addTile("tile-rock-01", 12, 4)
	map:addTile("tile-rock-03", 12, 5)
	map:addTile("tile-rock-big-01", 12, 6)
	map:addTile("tile-rock-02", 12, 8)
	map:addTile("tile-rock-01", 12, 9)
	map:addTile("tile-rock-big-01", 12, 10)
	map:addTile("tile-rock-03", 13, 2)
	map:addTile("tile-rock-big-01", 13, 3)
	map:addTile("tile-rock-01", 13, 5)
	map:addTile("tile-rock-big-01", 13, 8)
	map:addTile("tile-rock-01", 14, 0)
	map:addTile("tile-rock-02", 14, 1)
	map:addTile("tile-rock-01", 14, 2)
	map:addTile("tile-rock-02", 14, 5)
	map:addTile("tile-rock-03", 14, 6)
	map:addTile("tile-rock-01", 14, 7)
	map:addTile("tile-rock-02", 14, 10)
	map:addTile("tile-rock-01", 14, 11)

	map:addCave("tile-cave-02", 0, 4, "npc-grandpa", 3000)
	map:addCave("tile-cave-01", 0, 7, "npc-grandpa", 3000)

	map:addEmitter("tree", 4, 6, 1, 0, "")
	map:addEmitter("item-stone", 5, 3, 1, 1000, "")

	map:setSetting("width", "15")
	map:setSetting("height", "12")
	map:setSetting("fishnpc", "false")
	map:setSetting("flyingnpc", "false")
	map:setSetting("gravity", "9.81")
	map:setSetting("introwindow", "introtree")
	map:setSetting("packagetransfercount", "2")
	map:setSetting("playerX", "7")
	map:setSetting("playerY", "7")
	map:setSetting("points", "100")
	map:setSetting("referencetime", "30")
	map:setSetting("sideborderfail", "false")
	map:setSetting("theme", "rock")
	map:setSetting("tutorial", "true")
	map:setSetting("waterchangespeed", "0")
	map:setSetting("waterfallingdelay", "0")
	map:setSetting("waterheight", "0.8")
	map:setSetting("waterrisingdelay", "0")
	map:setSetting("wind", "0")
end
