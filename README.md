# pw

Wayland port of the X11 `pw` color picker. **Requires a wlroots-based
compositor** (Sway, Hyprland, river, etc.) — it uses `wlr-layer-shell-unstable-v1`
and `wlr-screencopy-unstable-v1`, wlroots extensions not present on
GNOME/KDE's portal stack.

## Everything is in `main.c`

Unlike a typical Wayland client, this isn't `main.c` + a separate
`wayland-scanner`-generated header you have to build first. The generated
protocol code for `wlr-layer-shell` and `wlr-screencopy` (normally produced
by running `wayland-scanner` against protocol XML at build time) has been
inlined directly into `main.c`, in a clearly marked section, copyright
notices intact. There is no `generated/` folder to find missing, and no
scanner step — just:

```sh
make
sudo make install      # installs to /usr/local/bin/pw
sudo make uninstall    # removes it
```

`protocols/` still contains the original two protocol XML files
(`wlr-layer-shell-unstable-v1.xml`, `wlr-screencopy-unstable-v1.xml`) purely
as reference / in case you ever want to regenerate that section yourself —
the build does **not** read them.

## Why a Wayland port can't be 1:1 with the X11 version

X11 lets any client read arbitrary root-window pixels and grab the pointer
globally. Wayland deliberately has neither capability, so the architecture
had to change:

- **Pixel sampling**: a single `wlr-screencopy` capture of the whole output
  is taken once at startup and held in memory. The magnifier/swatch show a
  *frozen frame* of the desktop, not a live feed — there's no synchronous
  "sample this pixel now" call in Wayland. Same approach used by other
  Wayland pickers (hyprpicker, wl-color-picker).
- **Picker UI**: instead of small floating windows positioned at root
  coordinates, the whole thing is one fullscreen `zwlr_layer_surface_v1` on
  the overlay layer with exclusive keyboard interactivity. The magnifier and
  swatch are drawn as panels inside that surface, near the simulated
  pointer, in surface-local coordinates.
- **Single output only**: the first `wl_output` advertised is used;
  multi-monitor setups will only get the picker on that one output.
- **Clipboard**: `wl-copy` (from `wl-clipboard`) replaces `xclip`. Make sure
  it's installed.
- **`xdg_popup_interface` stub**: `wlr-layer-shell`'s (unused) `get_popup`
  request signature references the `xdg_popup` type, which would normally
  require also generating/linking the entire ~2400-line xdg-shell protocol.
  Since that request is never called, `main.c` includes a 3-line empty
  stub interface instead — satisfies the linker, changes nothing at
  runtime, documented inline where it appears.

## Build dependencies

`libwayland-dev` (or just the runtime `libwayland-client`/headers),
`libxkbcommon-dev`, `libcairo2-dev`. `wayland-scanner` is **not** required
to build this package, since its output is already inlined — it's only
needed if you choose to regenerate the protocol section from `protocols/`
yourself.

## Run

```sh
./pw [-h] [-xrvca] [-t seconds]
```

Same flags/semantics as the X11 version. Left-click to pick, any key to
cancel. Tunables (`GRID_CELLS`, `CELL_pw`, `CORNER_R`, `SW_W`, `SW_H`) are
still compile-time constants near the top of `main.c`.

## Known rough edges

- No cursor-shape protocol wired up, so the OS cursor stays the normal arrow
  over the picker surface instead of becoming a crosshair — cosmetic only.
- No HiDPI/output-scale buffer scaling applied yet (`wl_output`'s scale is
  read but not multiplied into buffer dimensions) — fine on 1x outputs,
  will look soft/offset on scaled ones.
