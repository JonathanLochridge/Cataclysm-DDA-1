#pragma once
#ifndef CATA_SRC_BALLISTICS_H
#define CATA_SRC_BALLISTICS_H

#include "weakpoint.h"

class Creature;
class dispersion_sources;
class vehicle;
struct dealt_projectile_attack;
struct projectile;
struct tripoint;

/** Aim result for a single projectile attack */
struct projectile_attack_aim {
    ///< Hit quality, where 0.0 is a perfect hit and 1.0 is a miss
    double missed_by = 0;
    ///< Number of tiles the attack missed by
    double missed_by_tiles = 0;
    ///< Dispersion of this particular shot in arcminutes
    double dispersion = 0;
};

/**
 * Evaluates dispersion sources, range, and target to determine attack trajectory.
 **/
projectile_attack_aim projectile_attack_roll( const dispersion_sources &dispersion, double range,
        double target_size );

/**
 *  Fires a projectile at the target point from the source point with total_dispersion
 *  dispersion.
 *  Returns the rolled dispersion of the shot and the actually hit point.
 */
dealt_projectile_attack projectile_attack( const projectile &proj_arg, const tripoint &source,
        const tripoint &target_arg, const dispersion_sources &dispersion,
        Creature *origin = nullptr, const vehicle *in_veh = nullptr,
        const weakpoint_attack &attack = weakpoint_attack(), bool first = true );

#endif // CATA_SRC_BALLISTICS_H
