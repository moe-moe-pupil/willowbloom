---------------------------------------------------------------------
-- watchers (C) CompanyName, All Rights Reserved
-- Created by: AuthorName
-- Date: 2020-09-06 13:48:29
---------------------------------------------------------------------

-- To edit this template in: Data/Config/Template.lua
-- To disable this template, check off menuitem: Options-Enable Template File

---@class Blu_C
local Blu_C = {}
function getUrlFileName( strurl, strchar, bafter)

	local ts = string.reverse(strurl)
	local param1, param2 = string.find(ts, strchar)  -- 这里以"/"为例
	local m = string.len(strurl) - param2 + 1
	local result
	if (bafter == true) then
		result = string.sub(strurl, m+1, string.len(strurl))
	else
		result = string.sub(strurl, 1, m-1)
	end

	return result
end
EPropertyClass = import"EPropertyClass"
local uw=import "UserWidget"
local umg=import "GameplayStatics"
--print(package.path)
local info = debug.getinfo(1,"S")
local pathinfo = info.short_src
--由于获取的路径为反斜杠(\)所以用上面的函数转为正斜杠(/)
local path = string.gsub(pathinfo,"/","\\")
path=getUrlFileName(path,"\\",false)
local pathhtml = path
path=path .."\\"
pathhtml=getUrlFileName(pathhtml,"\\",false)
pathhtml=getUrlFileName(pathhtml,"\\",false)
print("pathhtml="..pathhtml)
--添加搜索路径

package.path = string.format("%s?.lua;%s?/init.lua;%s", path, path, package.path)
print(package.path)
JSON = assert((loadfile(path .."JSON.lua")))()
function Blu_C:ReceiveBeginPlay()
	self.bCanEverTick = true
	print("Blu_C Work~")
	local uiclass=slua.loadClass("/Game/SelectHtml.SelectHtml");
	--local ui = uiClass(gworld.CurrentLevel)
	local uworld = self:GetWorld()
	--local pc=self:GetFirstLocalPlayerFromController()
	self:createwidget(uiclass);
	self:lff(pathhtml.."\\HTML","*.html");
	self:fresh();
	print(_VERSION)
	self.Super:ReceiveBeginPlay()
end
function Blu_C:Tick(dt)
	--print("actor:Tick",self,dt)
	Blu_C:LineTrace()
end
function callback(content)
	json_table = JSON:decode(content)
	for key, value in pairs(json_table) do
		print(tostring(key)..":"..tostring(value))
	end
	json_str=JSON:encode(json_table)
	--print(content)
	print(json_table["chat"])
	print(json_str)
end
function fuckme()
	Blu_C:addscreenmsg("测试测试=w=~")
	Blu_C:restart()
end

return Blu_C