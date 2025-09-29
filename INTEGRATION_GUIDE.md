# DOOM Integration Guide

## Custom DOOM Build

This plugin uses a custom DOOM port built specifically for the Pexip plugin environment. The build is based on Mattias Gustavsson's DOOM-CRT project, which provides a clean, minimalistic port of the original DOOM source code.

## Build Process

The DOOM game is built using WAjic (WebAssembly JavaScript Interface Compiler) and includes:

- **Custom DOOM port**: Based on the original Linux DOOM 1.10 source
- **WebAssembly compilation**: Using WAjic for browser compatibility
- **Embedded WAD file**: DOOM1.WAD is embedded directly in the HTML
- **Canvas sharing**: Built-in support for real-time gameplay sharing

## Features

- ✅ No networking issues (solves alignment faults)
- ✅ Vanilla DOOM compatibility
- ✅ CRT filter effects
- ✅ Music support with OPL emulation
- ✅ Touch and keyboard controls
- ✅ Real-time canvas sharing
- ✅ Self-contained (no external dependencies)

## File Structure

```
public/
├── doom-crt.html     # Custom DOOM build (WebAssembly + HTML)
├── icon.png          # Plugin icon
└── manifest.json     # Plugin manifest
```

## Rebuilding DOOM

If you need to rebuild the DOOM game:

1. **Get the source**: Download from the original DOOM-CRT repository
2. **Install WAjic**: Download the WAjic build tools
3. **Obtain DOOM1.WAD**: You must provide your own copy of DOOM1.WAD (copyrighted game data) and place it in the `doom-source/` directory
4. **Build**: Run `cd doom-source && wasm/node wasm/wajicup.js doom.c doom.html -embed DOOM1.WAD DOOM1.WAD -rle -template template.html`
5. **Replace**: Copy the generated `doom.html` to `public/doom-crt.html`

**Important**: DOOM1.WAD is copyrighted material and is not included in this repository. You must obtain it separately from a legitimate source.

## Integration Notes

- The DOOM game automatically starts canvas sharing when loaded
- Canvas data is sent via `postMessage` to the parent plugin
- The plugin handles the sharing logic and sends frames to participants
- No external WAD files or assets are required
