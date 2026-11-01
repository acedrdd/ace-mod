# Ace Cull (Minecraft Bedrock 1.26.60, LeviLaunchroid preload-native mod)

Entity culling + RAM optimizer. Culling is ON by default.

## Build from your phone
1. Create a new GitHub repo.
2. Upload these 4 files to the repo root: AceCull.cpp, AceConfig.hpp, CMakeLists.txt, manifest.json
3. Add file > Create new file, name it `.github/workflows/build.yml`, paste the contents of build.yml.
4. Actions tab > "Build Ace Cull" > Run workflow.
5. When it finishes, open the run, download the artifact `AceCull-1.26.60`
   (a zip containing `AceCull-1.26.60.levipack`), extract it, import the .levipack in the launcher.

## In game (Mod Menu > Ace Cull)
- Entity Cull: on/off
- Heavy Culling: culls at 60% of the distance
- Cull Distance: 16-160 blocks (default 64)
- RAM Optimizer + interval (default every 30 s)

## Safety
- The cull hook is only installed if the entity callback is found exactly once AND its
  three struct offsets can be read from the game's own code. Otherwise it logs why and
  only the RAM optimizer runs.
- If the game closes early twice in a row with culling armed, culling stays off until you
  toggle the module off and on.
