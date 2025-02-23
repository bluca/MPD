/*
 * Copyright 2003-2022 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_PLAYER_LISTENER_HXX
#define MPD_PLAYER_LISTENER_HXX

class PlayerListener {
public:
	/**
	 * A playback error has occurred and
	 * PlayerControl::CheckRethrowError() will provide details.
	 */
	virtual void OnPlayerError() noexcept = 0;

	/**
	 * Some state of the player has changed.  This maps to
	 * #IDLE_PLAYER.
	 */
	virtual void OnPlayerStateChanged() noexcept = 0;

	/**
	 * Some options of the player has changed.  This maps to
	 * #IDLE_OPTIONS.
	 */
	virtual void OnPlayerOptionsChanged() noexcept = 0;

	/**
	 * Must call playlist_sync().
	 */
	virtual void OnPlayerSync() noexcept = 0;

	/**
	 * The current song's tag has changed.
	 */
	virtual void OnPlayerTagModified() noexcept = 0;

	/**
	 * Playback went into border pause.
	 */
	virtual void OnBorderPause() noexcept = 0;
};

#endif
